#!/usr/bin/env python3
"""
Backend API server for Educational Problems frontend
Handles problem addition requests and interfaces with the shell script
"""

import json
import subprocess
import tempfile
import os
from http.server import HTTPServer, BaseHTTPRequestHandler
from urllib.parse import urlparse, parse_qs
import sys

class ProblemHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        """Serve the frontend HTML file"""
        if self.path == '/' or self.path == '/index.html':
            self.send_response(200)
            self.send_header('Content-type', 'text/html')
            self.end_headers()
            
            # Serve the index.html file
            try:
                with open('/home/mohimenul/Educational-Problems/frontend/index.html', 'r') as f:
                    self.wfile.write(f.read().encode())
            except FileNotFoundError:
                self.send_error(404, "Frontend file not found")
        else:
            self.send_error(404, "File not found")
    
    def do_POST(self):
        """Handle problem addition requests"""
        if self.path == '/api/add-problem':
            try:
                # Parse JSON data
                content_length = int(self.headers['Content-Length'])
                post_data = self.rfile.read(content_length)
                data = json.loads(post_data.decode('utf-8'))
                
                # Validate required fields
                required_fields = ['url', 'tag', 'difficulty']
                for field in required_fields:
                    if not data.get(field):
                        self.send_json_response({
                            'success': False,
                            'error': f'Missing required field: {field}'
                        }, 400)
                        return
                
                # Add the problem using the shell script
                result = self.add_problem(data)
                
                if result['success']:
                    self.send_json_response(result, 200)
                else:
                    self.send_json_response(result, 500)
                    
            except json.JSONDecodeError:
                self.send_json_response({
                    'success': False,
                    'error': 'Invalid JSON data'
                }, 400)
            except Exception as e:
                self.send_json_response({
                    'success': False,
                    'error': str(e)
                }, 500)
        else:
            self.send_error(404, "API endpoint not found")
    
    def add_problem(self, data):
        """Add problem using the shell script logic"""
        try:
            # Change to the repository directory
            repo_path = '/home/mohimenul/Educational-Problems'
            os.chdir(repo_path)
            
            # Check if solution.cpp exists
            if not os.path.exists('solution.cpp'):
                return {
                    'success': False,
                    'error': 'solution.cpp not found. Make sure you have solved the problem first!'
                }
            
            # Find the next solution number
            codes_dir = 'codes'
            if not os.path.exists(codes_dir):
                os.makedirs(codes_dir)
            
            highest_num = 0
            for filename in os.listdir(codes_dir):
                if filename.startswith('solution') and filename.endswith('.cpp'):
                    try:
                        num_str = filename.replace('solution', '').replace('.cpp', '')
                        if num_str == '':
                            num = 0
                        else:
                            num = int(num_str)
                        highest_num = max(highest_num, num)
                    except ValueError:
                        continue
            
            next_num = highest_num + 1
            new_filename = f'solution{next_num}.cpp'
            
            # Copy solution.cpp to codes directory
            subprocess.run(['cp', 'solution.cpp', f'codes/{new_filename}'], check=True)
            
            # Update README.md
            self.update_readme(data, next_num, new_filename)
            
            # Git operations
            subprocess.run(['git', 'pull'], check=True)
            subprocess.run(['git', 'add', f'codes/{new_filename}', 'README.md'], check=True)
            commit_msg = f"Add new problem solution: {data['tag']} - {data['difficulty']}"
            subprocess.run(['git', 'commit', '-m', commit_msg], check=True)
            subprocess.run(['git', 'push'], check=True)
            
            return {
                'success': True,
                'message': f'Problem added successfully as {new_filename}',
                'problemNumber': next_num
            }
            
        except subprocess.CalledProcessError as e:
            return {
                'success': False,
                'error': f'Git operation failed: {e}'
            }
        except Exception as e:
            return {
                'success': False,
                'error': f'Failed to add problem: {e}'
            }
    
    def update_readme(self, data, problem_num, filename):
        """Update README.md with new problem entry"""
        # Format takeaway and revisit fields - properly escape for markdown
        takeaway_field = ""
        revisit_field = ""
        
        if data.get('takeaway'):
            # Clean and escape the text for markdown table
            takeaway_text = self.clean_text_for_markdown(data['takeaway'])
            takeaway_field = f'<details><summary>View</summary>{takeaway_text}</details>'
        
        if data.get('revisit'):
            # Clean and escape the text for markdown table
            revisit_text = self.clean_text_for_markdown(data['revisit'])
            revisit_field = f'<details><summary>View</summary>{revisit_text}</details>'
        
        # Create the new entry
        entry = f"| {problem_num} | [Link]({data['url']}) | {data['tag']} | {data['difficulty']} | {takeaway_field} | {revisit_field} | [Solution](./codes/{filename}) |"
        
        # Read current README
        with open('README.md', 'r') as f:
            content = f.read()
        
        # Insert the new entry before the marker comment
        marker = "<!-- PROBLEMS_TABLE_CONTENT -->"
        if marker in content:
            content = content.replace(marker, f"{entry}\n{marker}")
        else:
            # Fallback: add at the end of the table
            lines = content.split('\n')
            for i, line in enumerate(lines):
                if line.startswith('|---'):
                    # Found table header separator, insert after last table row
                    j = i + 1
                    while j < len(lines) and lines[j].startswith('|'):
                        j += 1
                    lines.insert(j, entry)
                    break
            content = '\n'.join(lines)
        
        # Write updated README
        with open('README.md', 'w') as f:
            f.write(content)
    
    def clean_text_for_markdown(self, text):
        """Clean and format text for markdown table cells"""
        if not text:
            return ""
        
        # Remove extra whitespace and normalize newlines
        text = text.strip()
        
        # Escape HTML characters FIRST (before adding our <br> tags)
        # This prevents user input from breaking the HTML
        text = text.replace('&', '&amp;')  # Must be first!
        text = text.replace('<', '&lt;').replace('>', '&gt;')
        
        # NOW replace newlines with <br> tags (these won't be escaped)
        text = text.replace('\n\n', '<br><br>')  # Double newlines become double breaks
        text = text.replace('\n', '<br>')        # Single newlines become single breaks
        
        # Escape pipe characters that would break markdown table
        text = text.replace('|', '&#124;')
        
        return text
    
    def send_json_response(self, data, status_code):
        """Send JSON response"""
        self.send_response(status_code)
        self.send_header('Content-type', 'application/json')
        self.send_header('Access-Control-Allow-Origin', '*')
        self.send_header('Access-Control-Allow-Methods', 'GET, POST, OPTIONS')
        self.send_header('Access-Control-Allow-Headers', 'Content-Type')
        self.end_headers()
        self.wfile.write(json.dumps(data).encode())
    
    def do_OPTIONS(self):
        """Handle CORS preflight requests"""
        self.send_response(200)
        self.send_header('Access-Control-Allow-Origin', '*')
        self.send_header('Access-Control-Allow-Methods', 'GET, POST, OPTIONS')
        self.send_header('Access-Control-Allow-Headers', 'Content-Type')
        self.end_headers()

def main():
    port = int(sys.argv[1]) if len(sys.argv) > 1 else 8000
    
    print(f"🚀 Educational Problems Frontend Server")
    print(f"📡 Server starting on port {port}")
    print(f"🌐 Open http://localhost:{port} in your browser")
    print(f"📁 Serving from: /home/mohimenul/Educational-Problems/frontend/")
    print(f"⚡ Press Ctrl+C to stop\n")
    
    server = HTTPServer(('localhost', port), ProblemHandler)
    
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print(f"\n🛑 Server stopped")
        server.server_close()

if __name__ == '__main__':
    main()

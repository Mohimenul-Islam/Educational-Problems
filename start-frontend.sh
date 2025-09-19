#!/bin/bash
# Start the Educational Problems Frontend Server

echo "🚀 Starting Educational Problems Frontend..."
echo "📁 Repository: /home/mohimenul/Educational-Problems"
echo ""

cd /home/mohimenul/Educational-Problems/frontend

# Check if Python 3 is available
if ! command -v python3 &> /dev/null; then
    echo "❌ Error: Python 3 is not installed or not in PATH"
    echo "Please install Python 3 to use the frontend"
    exit 1
fi

# Start the server
echo "🌐 Starting server on http://localhost:8000"
echo "📝 You can now add problems through the web interface!"
echo ""
echo "Press Ctrl+C to stop the server"
echo "----------------------------------------"

python3 server.py 8000

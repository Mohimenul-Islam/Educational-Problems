# Frontend Interface for Educational Problems

This directory contains a web-based frontend interface for adding problems to your Educational Problems repository. No more struggling with terminal input!

## 🌟 Features

- **Clean Web Interface**: Beautiful, responsive design that works on desktop and mobile
- **Multi-line Text Support**: Large text areas for takeaways and revisit notes
- **Live Preview**: See exactly how your problem will look before adding
- **Input Validation**: Ensures all required fields are filled and URLs are valid
- **Real-time Feedback**: Shows success/error messages and processing status
- **Auto Git Integration**: Automatically commits and pushes to GitHub

## 🚀 Quick Start

1. **Start the server:**
   ```bash
   ./start-frontend.sh
   ```

2. **Open your browser:**
   - Go to `http://localhost:8000`

3. **Add problems easily:**
   - Fill in the form fields
   - Use the large text areas for takeaways and revisit notes
   - Preview before submitting
   - Click "Add Problem" when ready

## 📋 How It Works

1. **Frontend (`index.html`)**: Web interface with form and validation
2. **Backend (`server.py`)**: Python server that processes requests
3. **Integration**: Backend uses same logic as your shell script
4. **Git Operations**: Automatically handles repository updates

## 🎯 Usage

### Required Fields:
- **Problem URL**: Link to the problem
- **Category/Tag**: Problem type (e.g., "Greedy", "Dynamic Programming")  
- **Difficulty**: Difficulty level (e.g., "Div2C", "Easy", "Hard")

### Optional Fields:
- **Key Takeaway**: Multi-line text area for learnings and insights
- **Revisit Note**: Multi-line text area for future review notes or error logs

### Example Workflow:
1. Solve problem in `solution.cpp`
2. Start frontend: `./start-frontend.sh`
3. Open browser to `http://localhost:8000`
4. Fill form with problem details
5. Preview to check everything looks good
6. Submit - automatically added to repository and pushed to GitHub!

## 🔧 Technical Details

- **Backend**: Python 3 HTTP server
- **Port**: 8000 (customizable in `server.py`)
- **Dependencies**: Only Python 3 (no additional packages needed)
- **Git Integration**: Same logic as your existing `add_problem.sh` script
- **File Management**: Automatically handles solution numbering and file copying

## 🛠️ Troubleshooting

**Server won't start:**
- Make sure Python 3 is installed: `python3 --version`
- Check if port 8000 is available
- Ensure you're in the repository directory

**Form submission fails:**
- Check that `solution.cpp` exists in the root directory
- Ensure git is configured and you can push to GitHub
- Check terminal output for detailed error messages

**Browser can't connect:**
- Make sure the server is running
- Try `http://127.0.0.1:8000` instead of localhost
- Check firewall settings

## 📝 Notes

- The frontend serves the same purpose as `add_problem.sh` but with a much better interface
- All Git operations (pull, commit, push) happen automatically
- Problem numbering is handled automatically (finds highest existing number + 1)
- The server needs to keep running while you're using the frontend
- Press Ctrl+C in terminal to stop the server when done

## 🎨 Customization

You can modify:
- **Port**: Change the port number in `start-frontend.sh` or `server.py`
- **Styling**: Edit the CSS in `index.html` to change the appearance
- **Form Fields**: Add or modify form fields in both `index.html` and `server.py`

This frontend makes adding problems much more pleasant - no more struggling with terminal input or multi-line text formatting!

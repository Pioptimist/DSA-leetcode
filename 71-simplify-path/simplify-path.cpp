class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string temp = "";
        
        // Add a trailing slash to easily process the very last directory
        path += "/"; 
        
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                // If we hit a slash and temp is not empty, process what we collected
                if (temp == "..") {
                    if (!stack.empty()) stack.pop_back();
                } 
                else if (temp != "." && temp != "") {
                    stack.push_back(temp);
                }
                // Reset temp for the next word
                temp = ""; 
            } else {
                // Not a slash? Keep building the word
                temp += path[i];
            }
        }
        
        // Build the final path from the stack
        string res = "";
        for (string dir : stack) {
            res += "/" + dir;
        }
        
        return res.empty() ? "/" : res;
    }
};
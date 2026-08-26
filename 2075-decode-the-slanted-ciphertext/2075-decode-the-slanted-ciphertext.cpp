class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1 || encodedText.empty()) return encodedText;
        
        int n = encodedText.length();
        int cols = n / rows;
        string originalText = "";

        // Traverse each diagonal starting from the first row
        for (int i = 0; i < cols; ++i) {
            int r = 0, c = i;
            while (r < rows && c < cols) {
                originalText += encodedText[r * cols + c];
                r++;
                c++;
            }
        }

        // Remove trailing spaces as originalText does not have any
        while (!originalText.empty() && originalText.back() == ' ') {
            originalText.pop_back();
        }

        return originalText;
    }
};
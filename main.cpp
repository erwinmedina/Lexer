#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// ********************** //
// Lexer/Scanner Function //
// ********************** //
void Lexer(std::string input_text, std::ofstream &myfile) {

    std::string charHolder; // Variable that will hold character strings

    // ----------------------------------------------------------- //
    // Creates the vectors for keywords, separators, and operators //
    // ----------------------------------------------------------- //
    std::vector<std::string> keywords = {"while", "if", "else", "min", "max", "for"};
    std::vector<char> separators = {';', '(', ')', '[', ']', '{', '}'};
    std::vector<char> operators = {'<', '>', '+', '-', '=', '*', '%'};

    // --------------------------- //
    // Iterates through input_text //
    // --------------------------- //
    for (int i = 0; i < input_text.length(); i++) {

        // ------------------------------------------------ //
        // Handles if white space and nothing in charHolder //
        // ------------------------------------------------ //
        if (input_text[i] == ' ' && charHolder == "") {
            continue;
        };

        // -------------------- //
        // Handles the keywords //
        // -------------------- //
        if (std::find(keywords.begin(), keywords.end(), charHolder) != keywords.end()) {
            myfile << "Keyword" << "\t\t\t" << charHolder << std::endl;
            charHolder = "";
        }

        // ---------------------- //
        // Handles the Separators //
        // ---------------------- //
        else if (std::find(separators.begin(), separators.end(), input_text[i]) != separators.end()) {

            // Handles if string in charHolder can be converted to float //
            try {
                float val = std::stof(charHolder);
                myfile << "Number" << "\t\t\t" << std::fixed << std::setprecision(2) << val << std::endl;
                charHolder = "";
            }
            // Handles if float failed, and is now an identifier // 
            catch(const std::invalid_argument) {
                if (charHolder != "") {
                    myfile << "Identifier" << "\t\t" << charHolder << std::endl;
                    charHolder = "";
                }
            }
            myfile << "Separator" << "\t\t" << input_text[i] << std::endl;
        }
        
        // --------------------- //
        // Handles the Operators //
        // --------------------- //
        else if (std::find(operators.begin(), operators.end(), input_text[i]) != operators.end()) {
            
            // Handles if string in charHolder can be converted to float //
            try {
                float val = std::stof(charHolder);
                myfile << "Number" << "\t\t\t" << std::fixed << std::setprecision(2) << val << std::endl;
                charHolder = "";
            }
            // Handles if float failed, and is now an identifier //
            catch(const std::invalid_argument) {
                if (charHolder != "") {
                    myfile << "Identifier" << "\t\t" << charHolder  << std::endl;
                    charHolder = "";
                }
            }

            myfile << "Operator" << "\t\t" << input_text[i] << std::endl;
        }

        // --------------------------------------------------------- //
        // If none of the above conditions, put char into charHolder //
        // --------------------------------------------------------- //
        else {
            charHolder.push_back(input_text[i]);
        };
    }
};

// ************* //
// Main Function //
// ************* //
int main() {

    // ------------------- //
    // Creates output file //
    // ------------------- //
    std::ofstream myfile;
    myfile.open("output_file.txt");
    myfile << "Token" << "\t\t\t" << "Lexeme\n" << std::endl;

    // ----------------------------------------- //
    // Opens input file, gets lines, calls Lexer //
    // ----------------------------------------- //
    std::string myText;
    std::ifstream MyReadFile("input_scode.txt");
    std::getline(MyReadFile, myText); // Stores line into 'myText'
    Lexer(myText, myfile);

    return 0;
}


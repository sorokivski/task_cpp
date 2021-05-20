#include<iostream>
#include<set>
#include<fstream>
#include<chrono>

int main() {

	system("color D");
	std::string x = " ";
	std::set<std::string> from_text;
	// getting text from cmd `till met ctrl+z combination
	// could be time counting
	//auto start = std:: chrono::high_resolution_clock::now();
	
	while (std:: cin >> x)
		from_text.insert(x);
	
	//auto end = std::chrono::high_resolution_clock::now();
	
	std::cout << from_text.size() << "\n";
	
	
	//std::chrono::duration<float> duration = end - start;
	//std::cout << "\n Time of compiling code from cmd: " << duration.count();
	/* outputing unique values
	 * for (auto &i : from_text) {
	 * std:: cout << "  " << i;
	}*/

	// getting text from file
	std::set<std::string> from_file;
	std::ifstream file;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	std::string path ="Text.txt";
	try {
		file.open(path);
		std::string word;
		
		//auto startfile = std::chrono::high_resolution_clock::now();
		
		while (!file.eof()) {
			
			word = " ";
			file >> word;
			from_file.insert(word);

		}
		
		//auto endfile = std::chrono::high_resolution_clock::now();
		//std::chrono::duration<float> duration = endfile - startfile;

		std:: cout << "\n"<<from_file.size() << "\n";
		//std::cout << "\n Time of compiling code from file: " << duration.count();
		
		file.close();
	}
	catch (const std:: ifstream:: failure &  ex) {
		system("color C");
		std::cout << "\nError of opening file!\n";
		std:: cout<<ex.what()<<std::endl<<ex.code();
		
	}
	
	return 0;
}

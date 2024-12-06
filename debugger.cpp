#include<bits/stdc++.h>
using namespace std;
#define ITERATIONS 100

void Help(){
	cout << "Usage: generator output solution (cpp files)\n"; 
}

int main(int argc, char **argv){
	int result = -1;
	if(argc != 4) Help();
	else{
		result = 0;
		//compile files 
		string generator = argv[1];
		string output = argv[2];
		string solution = argv[3];
		cout.flush();
		system(string("g++ -std=c++17 " + generator + ".cpp -o " + generator + ".exe").c_str());
		system(string("g++  -std=c++17 " + output + ".cpp -o " + output + ".exe").c_str());
		system(string("g++  -std=c++17 " + solution + ".cpp -o " + solution + ".exe").c_str());

		string gargs;
		cout << "enter generator arguments: ";
		getline(cin, gargs);
		cout << '\n';
		cout.flush();
		//run files
		for(int i = 0; i < ITERATIONS; i++){
			system(string(generator+".exe " + to_string(ITERATIONS) + ' ' + gargs + " > inputf.txt").c_str()); // 
			system(string(output+".exe" + " < inputf.txt > outputf.txt").c_str());
			system(string(solution+".exe" + " < inputf.txt > answerf.txt").c_str());
			//compare results
			system("fc outputf.txt answerf.txt");
		}
		
	} 
	return result;
}
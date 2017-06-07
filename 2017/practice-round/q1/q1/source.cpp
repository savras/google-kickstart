#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <fstream>

using std::cout;
using std::cin;
using std::unordered_set;
using std::string;
using std::ifstream;
using std::getline;

int main() {
	int T, N;	
	
	// Tests:
	// 1)
	// GOOGLE => GOLE
	// APAC CODE JAM => APCODEJM

	// 2)
	// Assume whitespaces are ignored and do not influence alphabetical order??
	// GOOG LE => GOLE
	// GOOGL A => GOLA

	ifstream myfile("A-large-practice.in");
	std::ofstream outfile("A-large-output.txt", std::ofstream::binary);

	string str, leader;
	int longestCount;
	unordered_set<char> us;

	if (myfile.is_open()) {
		myfile >> T;
		for(int i = 1; i <= T; i++) {
			myfile >> N;
			myfile.ignore();

			str = "";
			leader = "";
			longestCount = 0;			

			for (size_t m = 0; m < N; m++) {
				us.clear();
				bool isStrUnderTestEarlier = false;
				bool isEarliestSet = false;
				unordered_set<char>::const_iterator it;
				getline(myfile, str);

				if (N == 1) {
					cout << str << "\n";
				}
				else {
					for (size_t i = 0; i < str.length(); i++) {
						it = us.find(str[i]);
						if (str[i] != ' ' && it == us.end()) {	// DO NOT include space in hashset.
							us.insert(str[i]);
						}

						if (i < leader.length() && !isEarliestSet) {
							if (str[i] < leader[i]) {
								isStrUnderTestEarlier = true;
								isEarliestSet = true;
							}
							else if (leader[i] < str[i]) {
								isStrUnderTestEarlier = false;
								isEarliestSet = true;
							}
						}
					}
					int count = us.size();
					if (count > longestCount) {
						leader = str;
						longestCount = count;
					}
					else if (count == longestCount) {
						if (isStrUnderTestEarlier)
						{
							leader = str;
						}
					}
				}
			}
			outfile << "Case #" << i << ": " << leader << "\n";
		}
	}
	
	return 0;
}
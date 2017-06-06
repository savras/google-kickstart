#include "iostream"
#include "unordered_set"
#include "string"
#include "algorithm"

using std::cout;
using std::cin;
using std::unordered_set;
using std::string;

int main() {
	int T, N;	
	
	// Tests:
	// 1)
	// GOOGLE => GOLE
	// APAC CODE JAM => APCODEJM

	// 2)
	// Assume whitespaces are ignored and do not influence alphabetical order
	// GOOGLE => GOLE
	// GOOGLA => GOLA
	cin >> T;
	while (T--) {
		cin >> N;
		cin.ignore();

		string str;	
		string leader;		
		int longestCount = 0;
		unordered_set<char> us;

		for(size_t m = 0; m < N; m++) {
			us.clear();
			bool isStrUnderTestEarlier = false;
			bool isEarliestSet = false;
			unordered_set<char>::const_iterator it;			
			getline(cin, str);
			str.erase(remove_if(str.begin(), str.end(), isspace), str.end());

			if (N == 1) {
				cout << str << "\n";
			}
			else {
				int count = 0;
				for (size_t i = 0; i < str.length(); i++) {
					it = us.find(str[i]);
					if (it == us.end()) {
						count++;
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
		cout << leader << "\n";
	}
	return 0;
}
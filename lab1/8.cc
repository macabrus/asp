#include <iostream>
#include <regex>

using namespace std;


class SanitizedString {
	
	string s;

	public:
	
	string removeDuplicateWhitespace() {
		regex r("[ ]{2,}");
		return regex_replace(s, r, " ");
	}
	
	string removeNonAlphaChars() {
		regex r("[^A-Za-z]");
		return regex_replace(s, r, "");
	}

	
	SanitizedString(string s) : s(s) {}

	~SanitizedString() {}

	string getString() {return s;}

	string setString(string s) { this->s = s; }

};

int main () {
	SanitizedString s("Bok.    Ja   .    Sam   .    Mirko");
	SanitizedString s1(s.removeNonAlphaChars());
	s1.removeDuplicateWhitespace();
	cout << s1.getString();
}

#include <iostream>

using namespace std;

bool jeSlovo(char c) {
	return ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'));
}

int prebrojiSlova(string ulaz) {
	int num = 0;
	for (char c : ulaz)
		num += jeSlovo(c) ? 1 : 0;
	return num;
}

char* ostaviSlova(string ulaz) {
	char* samoSlova = (char*) malloc(sizeof(char) * prebrojiSlova(ulaz));
	char* slovaPtr = samoSlova;
	for(int i = 0; i < ulaz.length(); i++)
		if (jeSlovo(ulaz.at(i)))
			*(slovaPtr++) = ulaz.at(i);
	return samoSlova;
}

int main () {
	string s = "asp12_i_ASP13";
	char* ss = ostaviSlova(s);
	cout << ss;
	free(ss);
}

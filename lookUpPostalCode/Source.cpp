// Zip / Postal Code Lookup ? Enter a zip or postal code and have it return which city/cities that are in that zip code.

#include <stdio.h>
#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

bool isAlphabet(char a) {
	return 'A' <= toupper(a) && toupper(a) <= 'Z';
}

bool isNum(char a) {
	return '0' <= a && a <= '9';
}

// check if given string is formatted correctly
bool validPostalCode(string in) {
	if (in.size() == 6) {
		return isAlphabet(in.at(0)) && isNum(in.at(1)) && isAlphabet(in.at(2)) &&
			isNum(in.at(3)) && isAlphabet(in.at(4)) && isNum(in.at(5));
	}
	else if (in.size() == 7) {
		return isAlphabet(in.at(0)) && isNum(in.at(1)) && isAlphabet(in.at(2)) && in.at(3) == ' ' &&
			isNum(in.at(4)) && isAlphabet(in.at(5)) && isNum(in.at(6));
	}
}

void run(string in) {
	CURL *curl;
	CURLcode res;

	static const char *postthis = "moo mooo moo moo";

	// must be defined before using any curl functions
	// start a libcurl easy session
	// returns NULL if something went wrong
	curl = curl_easy_init();

	if (curl) {
		// curl_easy_setopt: set options
		curl_easy_setopt(curl, CURLOPT_URL, "www.google.ca");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postthis);

		/* if we don't provide POSTFIELDSIZE, libcurl will strlen() by
		itself */
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));

		/* always cleanup */
		curl_easy_cleanup(curl);
	}
}

int main(void)
{
	string in;
	while (1) {
		cout << "Input: ";
		getline(cin, in);

		if (!validPostalCode(in)) {
			cout << "Invalid postal code format" << endl;
		}
		else {
			run(in);
		}
	}
	return 0;
}
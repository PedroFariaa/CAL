#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>  
#include "Changes.h"

using namespace std;

//longest common subsequence
string LCS(string ref, string comp) {

	//swaps string in order to the comparisation be done comparing the shorter string with the longer
	if (ref.size() > comp.size())
		swap(ref, comp);

	unsigned int n = ref.size();
	unsigned int m = comp.size();

	vector<vector<unsigned int>> L(n + 1, vector<unsigned int>(m + 1));

	for (unsigned long int i = 0; i < ref.size(); i++)
		for (unsigned long int j = 0; j < comp.size(); j++)
			L[i][j] = 0;
	unsigned long int z = 0;

	string res;

	for (unsigned long int i = 0; i < ref.size(); i++) {
		for (unsigned long int j = 0; j < comp.size(); j++) {
			if (ref[i] == comp[j]) {
				if (i == 0 || j == 0) {
					L[i][j] = 1;
				}
				else {
					L[i][j] = L[i - 1][j - 1] + 1;
				}

				if (L[i][j] > z) {
					z = L[i][j];
					res = ref.substr(i - z + 1, z);
				}
				else if (L[i][j] == z) {
					res += ref.substr(i - z + 1, z);
				}
				else {
					L[i][j] = 0;
				}
			}
		}
	}
	return res;
}

double Similarity(string& ref, string& comp) {
	unsigned long int refSize = ref.size();
	unsigned long int compSize = comp.size();
	double res;

	//compares if two strings are exactly the same
	if (refSize == 0 && compSize == 0) {
		res = 1;
	}
	else {
		string stringRes;
		stringRes = LCS(ref, comp);
		res = stringRes.size();

		// similarity based in the length of the files
		res = (double)2 * res / (refSize + compSize);
	}
	return res;
}

// Methods used to Track the Changes between two diferent files
unsigned int levenshtein_distance(string &s1, string & s2) {
	const size_t len1 = s1.size(), len2 = s2.size();
	vector<unsigned int> col(len2 + 1), prevCol(len2 + 1);

	for (unsigned int i = 0; i < prevCol.size(); i++)
		prevCol[i] = i;
	for (unsigned int i = 0; i < len1; i++) {
		col[0] = i + 1;
		for (unsigned int j = 0; j < len2; j++)
			col[j + 1] = min(min(prevCol[1 + j] + 1, col[j] + 1),
			prevCol[j] + (s1[i] == s2[j] ? 0 : 1));
		col.swap(prevCol);
	}
	return prevCol[len2];
}

bool compareString(string s, string t) {
	unsigned int comp = levenshtein_distance(s, t);
	if (comp <= s.size() / 3 || comp <= t.size() / 3)
		return true;

	return false;
}


// Method responsable to save the tracked changes into a txt file
void SaveDifToFile(vector<Changes> Differences){
	string filename = "Output.txt";
	ofstream myfile(filename.c_str());

	for (unsigned int i = 0; i < Differences.size(); i++)
		myfile << Differences[i].getChange() << endl;

	myfile.close();
}

// Checks the two input files and looks for diferences between them
// this diferences will be saved on a txt file
void TrackChanges(vector<Changes> Differences, string tempRef, string tempComp) {
	string L1, L2;
	L1 = tempRef;
	L2 = tempComp;

	bool encontrou = false;
	int cont = 0;
	int cont2 = 0;
	stringstream nrline;
	string line;
	for (unsigned int i = 0; i < L2.size(); i++) {
		for (unsigned int d = cont; d < L1.size(); d++) {
			if (L2[i] == L1[d]) {
				Differences.push_back(Changes(L2, '>'));
				encontrou = true;
				cont++;
				break;
			}
			else if (compareString(L2, L1)) {
				line = "FA";
				nrline << (d + 1);
				line += nrline.str();
				nrline.str("");
				nrline.clear();
				Differences.push_back(Changes(L1, '~', line));
				line = "FN";
				nrline << (i + 1);
				line += nrline.str();
				nrline.str("");
				nrline.clear();
				Differences.push_back(Changes(L2, '~', line));
				encontrou = true;
				cont++;
				break;
			}
		}
		if (!encontrou) {
			line = "FN";
			nrline << (i + 1);
			line += nrline.str();
			nrline.str("");
			nrline.clear();
			Differences.push_back(Changes(L2, '+', line));
			cont2++;
		}

		encontrou = false;
		Differences.insert(Differences.begin() + i, Changes(L1, '-', line));
	}
	
	SaveDifToFile(Differences);
}


int main() {
	vector<Changes> Differences;
	string cont;
	do{
		string fileName = "", line = "", tempRef = "", tempComp = "";
		//reference file and comparisation file
		ifstream referenceFile;
		ifstream comparisationFile;
		//used to remove spaces and enters
		stringstream testReferenceFile, testComparisationFile;
		//files content
		string ReferenceFileContent, ComparisationFileContent;
		//maximum similarity introduced by the user
		double maxSimilarity;
		//similarity between files
		double limSimilarity;
		//files comparisation exceeds maximum similarity
		bool exceeds = false;

		//choosing the reference file
		cout << endl << endl;
		do {
			cout << "Escreva o nome do ficheiro de referencia ";
			cin >> fileName;
			referenceFile.open(fileName.c_str());
			if (!referenceFile.fail()) {
				cout << "Ficheiro aberto com sucesso!" << endl << endl;
			}
			else {
				cout << "Ficheiro nao existe!" << endl << endl;
			}
		} while (referenceFile.fail());

		//choosing the file to be compared
		cout << endl << endl;
		do {
			cout << "Escreva o nome do ficheiro a ser comparado ";
			cin >> fileName;
			comparisationFile.open(fileName.c_str());
			if (!comparisationFile.fail()) {
				cout << "Ficheiro aberto com sucesso!" << endl << endl;
			}
			else {
				cout << "Ficheiro nao existe!" << endl << endl;
			}
		} while (comparisationFile.fail());

		//reads file to test and copies it to a string
		if (referenceFile.is_open()) {
			while (referenceFile.good()) {
				getline(referenceFile, line);
				tempRef = line[line.length() - 1];
				testReferenceFile << line;
			}
			testReferenceFile << tempRef;
		}
		ReferenceFileContent = testReferenceFile.str();


		for (unsigned long int i = 0; i < ReferenceFileContent.length(); i++) {
			if (ReferenceFileContent[i] == ' ' || ReferenceFileContent[i] == '\n') {
				ReferenceFileContent.erase(i, 1);
			}
		}

		if (comparisationFile.is_open()) {
			while (comparisationFile.good()) {
				getline(comparisationFile, line);
				tempRef = line[line.length() - 1];
				testComparisationFile << line;
			}
			testComparisationFile << tempRef;
		}
		ComparisationFileContent = testComparisationFile.str();


		for (unsigned long int i = 0; i < ComparisationFileContent.length(); i++) {
			if (ComparisationFileContent[i] == ' ' || ComparisationFileContent[i] == '\n') {
				ComparisationFileContent.erase(i, 1);
			}
		}

		//chooses the maximum similarity before it's considered plagiarism
		do {
			cout << "Escreva o grau maximo de similaridade admissivel (1-100): ";
			cin >> maxSimilarity;
			if (maxSimilarity < 1 || maxSimilarity > 100) {
				cout << "O grau de similaridade introduzido nao e valido!" << endl << endl;
			}
		} while (maxSimilarity < 1 || maxSimilarity > 100);

		tempRef = ReferenceFileContent;
		tempComp = ComparisationFileContent;
		limSimilarity = Similarity(tempRef, tempComp) * 100.0;
		cout << limSimilarity << "% ";

		if (limSimilarity > maxSimilarity) {
			exceeds = true;
			cout << "O grau de similaridade foi excedido" << endl;
		}
		else {
			cout << "O grau de similaridade nao foi excedido" << endl;
		}


		TrackChanges(Differences, tempRef, tempComp);
		std::cout << "\nAs diferencas entre os dois ficheiros introduzidos foram registadas num ficheiro txt de Output";
		getchar();

		cout << endl << "\n\nQuer comparar ficheiros diferentes ?" << endl << "R: ";
		cin >> cont;

	}while (cont == "Y" || cont == "y");

	return 0;
}

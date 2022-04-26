#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include "utils.h"
#include "etudiant.h"

using namespace std;

vector<string> split(const string &, char);
vector<Etudiant> importer();
void exporter(vector<Etudiant>);
void ajouter(vector<Etudiant>);
void lister(vector<Etudiant>);
void modifier(vector<Etudiant>);
void supprimer();

#endif // UTILS_H_INCLUDED
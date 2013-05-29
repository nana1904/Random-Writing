/*
 * File: RandomWriter.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the random writer problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */

#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "map.h"
#include "random.h"
#include "strlib.h"
#include "vector.h"

using namespace std;

string read_seq(ifstream& infile, const int order){
    string seq;
    char ch;
    int i=0;
    while (infile.get(ch) && i<order){
	seq+=ch;
	++i;
    }
    return seq;
}


void analyze(Map<string, Vector<char> >& pattern, const int order){
    ifstream infile ("TomSawyer.txt");
    string seq=read_seq(infile,order);
    
    char ch;    
    while (infile.get(ch)){
	pattern[seq].push_back(ch);
	seq.erase(0,1);
	seq+=ch;
    }
}

string most_common_seq(const Map<string, Vector<char> >& pattern){
    string most_common_seq=*pattern.begin();
    foreach(string seq in pattern){
	most_common_seq=pattern[seq].size()>pattern[most_common_seq].size() ? seq : most_common_seq;
    }
    return most_common_seq;
}

string write_article(const Map<string, Vector<char> >& pattern, const string& initial_seed, int n_words){
    string seed=initial_seed;
    string article=seed;
    char ch;
    for (int i=seed.size(); i<n_words; ++i){
	if (pattern.containsKey(seed)){
	    ch=pattern[seed][randomInteger(0,pattern[seed].size()-1)];
	    article+=ch;
	    seed.erase(0,1);
	    seed+=ch;
	}else{
	    break;
	}
    }
    return article;
}


int main() {
    Map<string, Vector<char> > pattern;
    analyze(pattern,6);
    cout<<write_article(pattern, "He was", 1000)<<endl;
    return 0;
}

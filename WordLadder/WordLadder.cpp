/*
 * File: WordLadder.cpp
 * --------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the word ladder problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "console.h"
#include "lexicon.h"
#include "queue.h"
#include "simpio.h"
#include "vector.h"
using namespace std;

string findingnewch(string word, Lexicon lex, Lexicon lexused){
    string newWord;//
    
    for(int i=0;i<word.length();i++){//length not size()
	newWord =word;//init, avoid to change into other word
	for(char ch= 'a'; ch <= 'z'; ch++){
	    newWord.replace(i,1,1,ch);//repalce(position,len,size,char)
	    if(lex.contains(newWord) == true){
		if(lexused.contains(newWord) == false){	//avoid to recycle 	    
		    return newWord;
		}		    
	    }
	}

    }
    return "";
}

void searchingladder(Lexicon lex,string startWord, string endWord){

    Vector<string> newString;
    Vector<string> addToQueue;
    Queue < Vector<string> > firstQueue;
    
    Lexicon lexused;
    
    addToQueue.add(startWord);
    firstQueue.enqueue(addToQueue);
    
    while(firstQueue.size() != 0){
	newString=firstQueue.dequeue();
	for(;;){
	    string replaceString=findingnewch(newString[newString.size()-1],lex,lexused);//here, newstring contains serveral strings, so have to send the last word.
	    if(replaceString==endWord){
		foreach(string list in newString){
		    cout << list << "-";
		}
		cout <<endWord<<endl;
		return;
	    }

	    else if(replaceString != ""){  
		Vector<string>addNewtoQueue=newString; 
		addNewtoQueue.add(replaceString);
		firstQueue.enqueue(addNewtoQueue);
	    }
            else if(replaceString == ""){
		break;	    
	    }
	    lexused.add(replaceString);
	}

    }
    //no ladder
    if (firstQueue.size() == 0){
	    cout <<"no ladder" << endl;
	  
    }
    

}


int main() {
	// [TODO: fill in the code]
     Lexicon english("EnglishWords.dat");
     /*foreach (string word in english) {
	if(word.length()== 2){
	    cout << word <<endl;
	}
	if (english.contains("cork")== true ){
	    cout << "cork"<< endl;
	}

    }*/
     string start;
     string end;
     cin >> start;
     cin >> end;
     searchingladder(english,start,end);
     return 0;
}

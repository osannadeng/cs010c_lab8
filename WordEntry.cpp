#include "WordEntry.h"
#include "WordEntry.h"

// constructor, requires two parameters, numAppearances set to 1 when created
WordEntry::WordEntry(const string &text, int score)
 : word(text), numAppearances(1), totalScore(score) {}

// increases score by input and adds an appearance
void WordEntry::addNewAppearance(int score) {
	totalScore += score;
	++numAppearances;
}

// accessor that returns word
const string & WordEntry::getWord() const { return word; }

// returns average score of word base on totalScore and numAppearances
double WordEntry::getAverage() const {
	return static_cast<double>(totalScore) / numAppearances;
}

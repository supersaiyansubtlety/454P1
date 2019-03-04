from enum import Enum
states = Enum('e',  'a',  'b',  'c',  'ab',  'ac',  'ba',  'bc',  'ca',  'cb',  'aa',  'bb',  'cc',  'abc',  'acb',  'bac',  'bca',  'cab',  'cba',  'aab',  'aba',  'abb',  'aac',  'aca',  'acc',  'baa',  'bab',  'bba',  'bbc',  'bcb',  'bcc',  'caa',  'cac',  'cca',  'cbb',  'cbc',  'ccb',  'BAD')

k = 137
#int delta(int curState, int character);

def main():
	n = 137

	transitions = [[a,b,c],[aa,ab,ac],[ba,bb,bc],[ca,cb,cc],[aba,abb,abc],[aca,acb,acc],[baa,bab,bac],[bca,bcb,bcc],[caa,cab,cac],[cba,cbb,cbc],[BAD,aab,aac],[bba,BAD,bbc],[cca,ccb,BAD],[bca,bcb,bcc],[cba,cbb,cbc],[aca,acb,acc],[caa,cab,cac],[aba,abb,abc],[baa,bab,bac],[BAD,BAD,abc],[BAD,BAD,bac],[BAD,BAD,bbc],[BAD,acb,BAD],[BAD,cab,BAD],[BAD,ccb,BAD],[BAD,BAD,aac],[BAD,BAD,abc],[BAD,BAD,bac],[bca,BAD,BAD],[cba,BAD,BAD],[cca,BAD,BAD],[BAD,aab,BAD],[BAD,acb,BAD],[BAD,cab,BAD],[bba,BAD,BAD],[bca,BAD,BAD],[cba,BAD,BAD],[BAD,BAD,BAD]]
	currentCount = []
	nextCount = []

	for i in range(BAD):
		currentCount[i] = 1
		nextCount[i] = 0

	currentCount[BAD] = 0

	for i in range(n):
		for st in range(BAD):
			for let in range(3):
				if transitions[st][let] != BAD:
					nextCount[st] += currentCount[st]

		for i in range(BAD):
			currentCount[i] = nextCount[i]
			nextCount[i] = 0

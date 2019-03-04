from enum import Enum
import array
import numpy as np

class states(Enum):
  e = 0
  a = 1
  b = 2
  c = 3
  ab = 4
  ac = 5
  ba = 6
  bc = 7
  ca = 8
  cb = 9
  aa = 10
  bb = 11
  cc = 12
  abc = 13
  acb = 14
  bac = 15
  bca = 16
  cab = 17
  cba = 18
  aab = 19
  aba = 20
  abb = 21
  aac = 22
  aca = 23
  acc = 24
  baa = 25
  bab = 26
  bba = 27
  bbc = 28
  bcb = 29
  bcc = 30
  caa = 31
  cac = 32
  cca = 33
  cbb = 34
  cbc = 35
  ccb = 36
  BAD = 37


def main():
    #//number of strings accepted of length n

    n=int(input('enter an integer: '))
    transitions = [
        [states.a,states.b,states.c],
        [states.aa,states.ab,states.ac],
        [states.ba,states.bb,states.bc],
        [states.ca,states.cb,states.cc],
        [states.aba,states.abb,states.abc],
        [states.aca,states.acb,states.acc],
        [states.baa,states.bab,states.bac],
        [states.bca,states.bcb,states.bcc],
        [states.caa,states.cab,states.cac],
        [states.cba,states.cbb,states.cbc],
        [states.BAD,states.aab,states.aac],
        [states.bba,states.BAD,states.bbc],
        [states.cca,states.ccb,states.BAD],
        [states.bca,states.bcb,states.bcc],
        [states.cba,states.cbb,states.cbc],
        [states.aca,states.acb,states.acc],
        [states.caa,states.cab,states.cac],
        [states.aba,states.abb,states.abc],
        [states.baa,states.bab,states.bac],
        [states.BAD,states.BAD,states.abc],
        [states.BAD,states.BAD,states.bac],
        [states.BAD,states.BAD,states.bbc],
        [states.BAD,states.acb,states.BAD],
        [states.BAD,states.cab,states.BAD],
        [states.BAD,states.ccb,states.BAD],
        [states.BAD,states.BAD,states.aac],
        [states.BAD,states.BAD,states.abc],
        [states.BAD,states.BAD,states.bac],
        [states.bca,states.BAD,states.BAD],
        [states.cba,states.BAD,states.BAD],
        [states.cca,states.BAD,states.BAD],
        [states.BAD,states.aab,states.BAD],
        [states.BAD,states.acb,states.BAD],
        [states.BAD,states.cab,states.BAD],
        [states.bba,states.BAD,states.BAD],
        [states.bca,states.BAD,states.BAD],
        [states.cba,states.BAD,states.BAD]
    ]


    #//for states e through BAD-1 (no BAD b/c always ignored), number of reachable accept states
    currentCount = [3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    #//i+1'th column of reachable states count
    nextCount = np.zeros(states.BAD)

   # //calculate the i+1'th column of reachable accepting state counts
    for i in range(n):#//end at before n (i=n-1) because we're finding i+1'th column, so last  (n-1)+1'th
    #//go n times b/c string
        for st in range(states.BAD):
        #//for each state except BAD: e to BAD-1
            for let in range(3):
            #//'a'-'a'=0, 'c'-'a'=2, so i=0;i<=2,
                if transitions[st][let] != states.BAD:
                #//skip BAD b/c always 0
                    #//for i+1'th column, sum reachable states' counts from i'th column
                    nextCount[st] += currentCount[st]
                #end if
            #end for let
        #end for st

        #//next goes into current, next reset to 0's, stop before BAD b/c always 0 in both columns
        for j in range(states.BAD):
            currentCount[j] = nextCount[j]
            nextCount[j] = 0
        #end for i

    #end for i

    print("answer:(137)\t", "6119266976149912241614898841866546736\n", "found:(", n, ")\t\t", currentCount[0], "\n")

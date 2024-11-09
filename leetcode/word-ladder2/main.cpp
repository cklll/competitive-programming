
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<deque>
#include<queue>
#include<utility>
using namespace std;


// Memory Limit exceed (and possibly TLE as well)
class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> result;

    unordered_map<string, int> wordEarliestDepth;
    wordEarliestDepth[beginWord] = 0;

    unordered_map<string, vector<string>> wordMap;
    for (int i = 0; i < wordList.size(); i++) {
      if (diffByOne(beginWord, wordList[i])) {
        wordMap[beginWord].push_back(wordList[i]);
      }
    }

    for (int i = 0; i < wordList.size(); i++) {
      if (wordList[i] == beginWord) {
        continue;
      }

      for (int j = 0; j < wordList.size(); j++) {
        if (diffByOne(wordList[i], wordList[j])) {
          wordMap[wordList[i]].push_back(wordList[j]);
        }
      }
    }

    int minSolutionSize = -1;

    queue<vector<string>> nextStates;

    nextStates.push({beginWord});

// int i = 0;
    while (nextStates.size() > 0) {
      vector<string> state = nextStates.front();
      nextStates.pop();

      // if (i++ % 10000 == 0) {
      //   cout << nextStates.size() << " " << state[state.size()-1] << " " <<  state.size() << endl;
      // }

      // already have at least 1 solution and the new states have greater length -> no need to continue
      if (minSolutionSize != -1 && state.size() > minSolutionSize) {
        break;
      }

      string lastWord = state[state.size()-1];

      if (lastWord == endWord) {
        result.push_back(state);
        minSolutionSize = state.size();
        continue;
      }

      for (auto &word : wordMap[lastWord]) {
        // if we have already visited this word in an earlier depth, no need to visit it
        if (wordEarliestDepth.find(word) != wordEarliestDepth.end()) {
          if (state.size() > wordEarliestDepth[word]) {
            continue;
          }
        } else {
          // first time visiting this word
          wordEarliestDepth[word] = state.size();
        }

        vector<string> newState(state);
        newState.push_back(word);

        nextStates.push(newState);
      }
    }

    return result;
  }

  bool diffByOne(string &s1, string &s2) {
    int diffCount = 0;
    for (int i=0; i < s1.size(); i++) {
      if (s1[i] != s2[i]) {
        diffCount++;
        if (diffCount > 1) {
          return false;
        }
      }
    }

    return diffCount == 1;
  }
};

void printResult(vector<vector<string>> result) {
  for (auto &words : result) {
    for (auto &word : words) {
      cout << word << " ";
    }
    cout << endl;
  }
}


int main() {
  Solution sol;

  // vector<string> words = {"hot","dot","dog","lot","log","cog"};
  // printResult(sol.findLadders("hit", "cog", words));
  // [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]

  // vector<string> words = {"hot","dot","dog","lot","log"};
  // printResult(sol.findLadders("hit", "cog", words));
  // []

  // vector<string> words = {"a","b","c"};
  // printResult(sol.findLadders("a", "c", words));
  // [["a","c"]]

  vector<string> words = {"aaaaa","caaaa","cbaaa","daaaa","dbaaa","eaaaa","ebaaa","faaaa","fbaaa","gaaaa","gbaaa","haaaa","hbaaa","iaaaa","ibaaa","jaaaa","jbaaa","kaaaa","kbaaa","laaaa","lbaaa","maaaa","mbaaa","naaaa","nbaaa","oaaaa","obaaa","paaaa","pbaaa","bbaaa","bbcaa","bbcba","bbdaa","bbdba","bbeaa","bbeba","bbfaa","bbfba","bbgaa","bbgba","bbhaa","bbhba","bbiaa","bbiba","bbjaa","bbjba","bbkaa","bbkba","bblaa","bblba","bbmaa","bbmba","bbnaa","bbnba","bboaa","bboba","bbpaa","bbpba","bbbba","abbba","acbba","dbbba","dcbba","ebbba","ecbba","fbbba","fcbba","gbbba","gcbba","hbbba","hcbba","ibbba","icbba","jbbba","jcbba","kbbba","kcbba","lbbba","lcbba","mbbba","mcbba","nbbba","ncbba","obbba","ocbba","pbbba","pcbba","ccbba","ccaba","ccaca","ccdba","ccdca","cceba","cceca","ccfba","ccfca","ccgba","ccgca","cchba","cchca","cciba","ccica","ccjba","ccjca","cckba","cckca","cclba","cclca","ccmba","ccmca","ccnba","ccnca","ccoba","ccoca","ccpba","ccpca","cccca","accca","adcca","bccca","bdcca","eccca","edcca","fccca","fdcca","gccca","gdcca","hccca","hdcca","iccca","idcca","jccca","jdcca","kccca","kdcca","lccca","ldcca","mccca","mdcca","nccca","ndcca","occca","odcca","pccca","pdcca","ddcca","ddaca","ddada","ddbca","ddbda","ddeca","ddeda","ddfca","ddfda","ddgca","ddgda","ddhca","ddhda","ddica","ddida","ddjca","ddjda","ddkca","ddkda","ddlca","ddlda","ddmca","ddmda","ddnca","ddnda","ddoca","ddoda","ddpca","ddpda","dddda","addda","aedda","bddda","bedda","cddda","cedda","fddda","fedda","gddda","gedda","hddda","hedda","iddda","iedda","jddda","jedda","kddda","kedda","lddda","ledda","mddda","medda","nddda","nedda","oddda","oedda","pddda","pedda","eedda","eeada","eeaea","eebda","eebea","eecda","eecea","eefda","eefea","eegda","eegea","eehda","eehea","eeida","eeiea","eejda","eejea","eekda","eekea","eelda","eelea","eemda","eemea","eenda","eenea","eeoda","eeoea","eepda","eepea","eeeea","ggggg","agggg","ahggg","bgggg","bhggg","cgggg","chggg","dgggg","dhggg","egggg","ehggg","fgggg","fhggg","igggg","ihggg","jgggg","jhggg","kgggg","khggg","lgggg","lhggg","mgggg","mhggg","ngggg","nhggg","ogggg","ohggg","pgggg","phggg","hhggg","hhagg","hhahg","hhbgg","hhbhg","hhcgg","hhchg","hhdgg","hhdhg","hhegg","hhehg","hhfgg","hhfhg","hhigg","hhihg","hhjgg","hhjhg","hhkgg","hhkhg","hhlgg","hhlhg","hhmgg","hhmhg","hhngg","hhnhg","hhogg","hhohg","hhpgg","hhphg","hhhhg","ahhhg","aihhg","bhhhg","bihhg","chhhg","cihhg","dhhhg","dihhg","ehhhg","eihhg","fhhhg","fihhg","ghhhg","gihhg","jhhhg","jihhg","khhhg","kihhg","lhhhg","lihhg","mhhhg","mihhg","nhhhg","nihhg","ohhhg","oihhg","phhhg","pihhg","iihhg","iiahg","iiaig","iibhg","iibig","iichg","iicig","iidhg","iidig","iiehg","iieig","iifhg","iifig","iighg","iigig","iijhg","iijig","iikhg","iikig","iilhg","iilig","iimhg","iimig","iinhg","iinig","iiohg","iioig","iiphg","iipig","iiiig","aiiig","ajiig","biiig","bjiig","ciiig","cjiig","diiig","djiig","eiiig","ejiig","fiiig","fjiig","giiig","gjiig","hiiig","hjiig","kiiig","kjiig","liiig","ljiig","miiig","mjiig","niiig","njiig","oiiig","ojiig","piiig","pjiig","jjiig","jjaig","jjajg","jjbig","jjbjg","jjcig","jjcjg","jjdig","jjdjg","jjeig","jjejg","jjfig","jjfjg","jjgig","jjgjg","jjhig","jjhjg","jjkig","jjkjg","jjlig","jjljg","jjmig","jjmjg","jjnig","jjnjg","jjoig","jjojg","jjpig","jjpjg","jjjjg","ajjjg","akjjg","bjjjg","bkjjg","cjjjg","ckjjg","djjjg","dkjjg","ejjjg","ekjjg","fjjjg","fkjjg","gjjjg","gkjjg","hjjjg","hkjjg","ijjjg","ikjjg","ljjjg","lkjjg","mjjjg","mkjjg","njjjg","nkjjg","ojjjg","okjjg","pjjjg","pkjjg","kkjjg","kkajg","kkakg","kkbjg","kkbkg","kkcjg","kkckg","kkdjg","kkdkg","kkejg","kkekg","kkfjg","kkfkg","kkgjg","kkgkg","kkhjg","kkhkg","kkijg","kkikg","kkljg","kklkg","kkmjg","kkmkg","kknjg","kknkg","kkojg","kkokg","kkpjg","kkpkg","kkkkg","ggggx","gggxx","ggxxx","gxxxx","xxxxx","xxxxy","xxxyy","xxyyy","xyyyy","yyyyy","yyyyw","yyyww","yywww","ywwww","wwwww","wwvww","wvvww","vvvww","vvvwz","avvwz","aavwz","aaawz","aaaaz"};
  printResult(sol.findLadders("aaaaa", "ggggg", words));
  return 0;


}

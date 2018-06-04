#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    string s1;
    string s2;
    bool diff = false;
    bool first_more = false;
    cin >> s1 >> s2;
    string ans;
    for (int j = 0; j < s1.size(); j++) {
      if (s1[j] == '?') {
	if (diff) {
	  if (first_more) {
	    s1[j] = '0';
	    if (s2[j] == '?') s2[j] = '9';
	  }
	  else {
	    s1[j] = '9';
	    if (s2[j] == '?') s2[j] = '0';
	  }
	}
	else if (j == s1.size() - 1) {
	  if (s2[j] != '?') s1[j] = s2[j];
	  else s1[j] = '0', s2[j] = '0';
	}
	else {
	  char nt1 = s1[j + 1];
	  char nt2 = s2[j + 1];
	  if (nt1 == '?' || nt2 == '?') {
	    if (s2[j] == '?') s1[j] = '0', s2[j] = '0';
	    else s1[j] = s2[j];
	  }
	  else if (nt1 - nt2 > 5) {
	    diff = true;
	    if (s2[j] == '?') s1[j] = '0', s2[j] = '1';
	    else if (s2[j] > '0') s1[j] = s2[j] - 1;
	    else s1[j] = '0', first_more = true;
	  }
	  else if (nt2 - nt1 > 5) {
	    diff = true;
	    if (s2[j] == '?') s1[j] = '1', s2[j] = '0';
	    else if (s2[j] < '9') s1[j] = s2[j] + 1, first_more = true;
	    else s1[j] = s2[j];
	  }
	  else if (nt1 - nt2 == 5) {
	    if (s2[j] != '?') s1[j] = s2[j];
	    else s1[j] = '0', s2[j] = '0';
	    for (int k = j + 2; k < s1.size(); k++) {
	      if ((s1[k] == '?' && s2[k] > '0') || (s1[k] == '?' && s2[k] == '?') || (s1[k] != '?' && s2[k] != '?' && s2[k] > s1[k])) {
		if (s2[j] != '?') s1[j] = s2[j];
		else s1[j] = '0', s2[j] = '0';
		diff = true;
		first_more = true;
		break;
	      }
	      else if ((s2[k] == '?' && s1[k] > '0') || (s1[k] != '?' && s2[k] != '?' && s1[k] > s2[k])) {
		if (s2[j] != '?' && s2[j] > '0') s1[j] = s2[j] - 1;
		else {
		  s1[j] = '0';
		  if (s2[j] == '?') s2[j] = '1';
		}
		diff = true;
		break;
	      }
	    }
	  }
	  else if (nt2 - nt1 == 5) {
	    if (s2[j] != '?') s1[j] = s2[j];
	    else s1[j] = '0'; s2[j] = '0';
	    for (int k = j + 2; k < s1.size(); k++) {
	      
	      if ((s1[k] == '?' && s2[k] > '0') || (s1[k] == '?' && s2[k] == '?') || (s1[k] != '?' && s2[k] != '?' && s2[k] > s1[k])) {
		if (s2[j] != '?') s1[j] = s2[j];
		else s1[j] = '0', s2[j] = '0';
		diff = true;
		first_more = true;
		break;
	      }
	      else if ((s2[k] == '?' && s1[k] > '0') || (s1[k] != '?' && s2[k] != '?' && s1[k] > s2[k])) {
		if (s2[j] != '?' && s2[j] > '0') s1[j] = s2[j] - 1;
	      else {
		s1[j] = '0';
		if (s2[j] == '?') s2[j] = '1';
	      }
		diff = true;
		break;
	      }
	    }
	  }
	  else {
	    if (s2[j] != '?') s1[j] = s2[j];
	    else s1[j] = '0', s2[j] = '0';
	  }
	}
      }
      else if (s2[j] == '?') {
	if (diff) {
	  if (first_more) s2[j] = '9';
	  else s2[j] = '0';
	}
	else if (j == s1.size() - 1) {
	  s2[j] = s1[j];
	}
	else {
	  char nt1 = s1[j + 1];
	  char nt2 = s2[j + 1];
	  if (nt1 == '?' || nt2 == '?') {
	    s2[j] = s1[j];
	  }
	  else if (nt1 - nt2 > 5) {
	    diff = true;
	    if (s1[j] < '9') s2[j] = s1[j] + 1;
	    else s2[j] = s1[j], first_more = true;
	  }
	  else if (nt2 - nt1 > 5) {
	    diff = true;
	    if (s1[j] > '0') s2[j] = s1[j] - 1, first_more = true;
	    else s2[j] = s1[j];
	  }
	  else if (nt1 - nt2 == 5) {
	    s2[j] = s1[j];
	    for (int k = j + 2; k < s1.size(); k++) {
	      if ((s1[k] == '?' && s2[k] > '0') || (s1[k] == '?' && s2[k] == '?') || (s1[k] != '?' && s2[k] != '?' && s2[k] > s1[k])) {
		s2[j] = s1[j];
		diff = true;
		first_more = true;
		break;
	      }
	      else if ((s2[k] == '?' && s1[k] > '0') || (s1[k] != '?' && s2[k] != '?' && s1[k] > s2[k])) {
		if (s2[j] != '?' && s2[j] > '0') s1[j] = s2[j] - 1;
		else {
		  s1[j] = '0';
		  if (s2[j] == '?') s2[j] = '1';
		}
		diff = true;
		break;
	      }
	    }
	  }
	  else if (nt2 - nt1 == 5) {
	    s2[j] = s1[j];
	    for (int k = j + 2; k < s1.size(); k++) {
	      
	      if ((s1[k] == '?' && s2[k] > '0') || (s1[k] == '?' && s2[k] == '?') || (s1[k] != '?' && s2[k] != '?' && s2[k] > s1[k])) {
		if (s2[j] != '?') s1[j] = s2[j];
		else s1[j] = '0', s2[j] = '0';
		diff = true;
		first_more = true;
		break;
	      }
	      else if ((s2[k] == '?' && s1[k] > '0') || (s1[k] != '?' && s2[k] != '?' && s1[k] > s2[k])) {
		if (s2[j] != '?' && s2[j] > '0') s1[j] = s2[j] - 1;
		else {
		  s1[j] = '0';
		  if (s2[j] == '?') s2[j] = '1';
		}
		diff = true;
		break;
	      }
	    }
	  }
	  else {
	    s2[j] = s1[j];
	  }
	}
      }
      else {
	if (!diff) {
	  if (s1[j] > s2[j]) diff = true, first_more = true;
	  else if (s1[j] < s2[j]) diff = true;
	}
      }
    }
    cout << "Case #" << i << ": ";
    cout << s1 << ' ' << s2 << endl;
  }
}

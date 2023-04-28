#include <ctime>
#include <vector>
#include <deque>
#include <iostream>

std::vector<int> m_i_sort_vec(std::vector<int> vec) {

	size_t i;

	std::vector<int> a;
	std::vector<int> b;

	for (size_t x = 1; x < vec.size(); x += 2) {
		if (vec[x] < vec[x - 1]) {
			int tmp = vec[x];
			vec[x] = vec[x - 1];
			vec[x - 1] = tmp;
		}
	}
	std::vector<int> pairs;
	
	for (int i = 0; i < 2; i++) {
		if (!vec.empty()) {
			pairs.push_back(vec[0]);
			vec.erase(vec.begin());
		}
	}
			//il faut inserer les pairs de vec dans pairs.
	while (!vec.empty()) {
		if (vec.size() == 1) {
			pairs.push_back(vec[0]);
			vec.erase(vec.begin());
			break;
		}
		i = 1;
		while (i < pairs.size()) {
			if (vec[1] < pairs[i]) {
				pairs.insert(pairs.begin() + (i - 1), vec.begin(), vec.begin() + 2);
				vec.erase(vec.begin());
				vec.erase(vec.begin());
				break;
			}
			i += 2;
		}
		if (i >= pairs.size())
		{
			pairs.push_back(vec[0]);
			pairs.push_back(vec[1]);
			vec.erase(vec.begin());
			vec.erase(vec.begin());
		}
	}
	for (size_t x = 0; x < pairs.size(); x++) {
	    if (x % 2 == 0)
	        b.push_back(pairs[x]);
	    else
	        a.push_back(pairs[x]);
	}
	//insert b in a
	for (size_t x = 0; x < b.size(); x++) {
	    size_t y;
		if (x == 0)
			y = 0;
		else
			y = (x * 2) - 1;
	    for (size_t tmp = 0; tmp <= y; tmp++) {
	        if (b[x] < a[tmp]) {
	            a.insert(a.begin() + tmp, b[x]);
	            break;
	        }
			else if (tmp == y) {
				a.insert(a.begin() + tmp + 1, b[x]);
	            break;
			}

	    }
	}
	return (a);
}

std::deque<int> m_i_sort_deque(std::deque<int> deq) {

	size_t i;

	std::deque<int> a;
	std::deque<int> b;

	for (size_t x = 1; x < deq.size(); x += 2) {
		if (deq[x] < deq[x - 1]) {
			int tmp = deq[x];
			deq[x] = deq[x - 1];
			deq[x - 1] = tmp;
		}
	}
	std::deque<int> pairs;
	
	for (int i = 0; i < 2; i++) {
		if (!deq.empty()) {
			pairs.push_back(deq[0]);
			deq.pop_front();
		}
	}
			//il faut inserer les pairs de vec dans pairs.
	while (!deq.empty()) {
		if (deq.size() == 1) {
			pairs.push_back(deq[0]);
			deq.pop_front();
			break;
		}
		i = 1;
		while (i < pairs.size()) {
			if (deq[1] < pairs[i]) {
				pairs.insert(pairs.begin() + (i - 1), deq.begin(), deq.begin() + 2);
				deq.pop_front();
				deq.pop_front();
				break;
			}
			i += 2;
		}
		if (i >= pairs.size())
		{
			pairs.push_back(deq[0]);
			pairs.push_back(deq[1]);
			deq.pop_front();
			deq.pop_front();
		}
	}

	for (size_t x = 0; x < pairs.size(); x++) {
	    if (x % 2 == 0)
	        b.push_back(pairs[x]);
	    else
	        a.push_back(pairs[x]);
	}
	//insert b in a
	for (size_t x = 0; x < b.size(); x++) {
	    size_t y;
		if (x == 0)
			y = 0;
		else
			y = (x * 2) - 1;
	    for (size_t tmp = 0; tmp <= y; tmp++) {
	        if (b[x] < a[tmp]) {
	            a.insert(a.begin() + tmp, b[x]);
	            break;
	        }
			else if (tmp == y) {
				a.insert(a.begin() + tmp + 1, b[x]);
	            break;
			}

	    }
	}
	return (a);
}
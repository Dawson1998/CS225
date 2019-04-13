#include <unordered_map>

using namespace std;

unordered_map<string, int> common_elems(unordered_map<string, int> &mapA,
                                        unordered_map<string, int> &mapB) {

    // your code here
    unordered_map<string, int> common;

    for (std::pair<string, int> element : mapA) {
      unordered_map<string, int>::iterator it = mapB.find(element.first);

      if (it != mapB.end()) {
        common.insert(std::pair<string, int>(element.first, element.second + it->second));
      }
    }

    for (std::pair<string, int> element : common) {
      mapA.erase(element.first);
      mapB.erase(element.first);
    }

    return common;
}

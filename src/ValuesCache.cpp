#include "ValuesCache.h"

sValue ValuesCache::getFirst() {
    sValue val = front();
    erase(begin());
    return val;
}


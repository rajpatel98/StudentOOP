#include <cassert>
#include "../my_code/hello.h"


int main() {
	int ret = sayHello();
    assert(ret == 0);
    return ret;
}

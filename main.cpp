#define BLACKTEA

#ifdef BLACKTEA
// BlackTea
#include <BlackTea>
#else
// Android-ML
#include <stdio.h>
#include <stdlib.h>
#include "inlineHook.h"
#endif

namespace h_gameManager {
	bool (*o_isIconUnlocked)(void* self, int, int);
	bool isIconUnlocked(void* self, int id, int icontype) {
		return true;
	}
	bool (*o_isColorUnlocked)(void* self, int, bool);
	bool isColorUnlocked(void* self, int id, bool unk_1) {
		return true;
	}
}

#ifdef BLACKTEA
// BlackTea
Init {
	CreateHook("_ZN11GameManager14isIconUnlockedEi8IconType", h_gameManager, isIconUnlocked, o_isIconUnlocked);
	CreateHook("_ZN11GameManager15isColorUnlockedEib", h_gameManager, isColorUnlocked, o_isColorUnlocked);
}
#else
// Android-ML
__attribute__((constructor))
void fdml_init() {
  hook("_ZN11GameManager14isIconUnlockedEi8IconType", h_gameManager, isIconUnlocked, o_isIconUnlocked);
  hook("_ZN11GameManager15isColorUnlockedEib", h_gameManager, isColorUnlocked, o_isColorUnlocked);
  inlineHookAll();
}
#endif

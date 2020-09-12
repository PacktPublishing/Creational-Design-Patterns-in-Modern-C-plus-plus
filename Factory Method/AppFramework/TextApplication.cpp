#include "TextApplication.h"
#include "TextDocument.h"

DocumentPtr TextApplication::Create() {
	return std::make_unique<TextDocument>();
}

#include "SpreadSheetApplication.h"
#include "SpreadsheetDocument.h"

DocumentPtr SpreadSheetApplication::Create() {
	return std::make_unique<SpreadsheetDocument>() ;
}

#include "sink.h"

//change our PNMwriter to PNMwriterCPP
class PNMwriterCPP : public sink {
	public:
		void Write(char *filename);
};


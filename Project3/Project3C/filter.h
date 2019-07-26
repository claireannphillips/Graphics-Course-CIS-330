#include "source.h"
#include "sink.h"
#include <stdio.h>

class Filter: public source, public sink {
};

class Shrinker : public Filter {
	//Shrinker is derived from Filter 
	public:
		virtual void Execute();
};

class LRCombine : public Filter {
	//LRCombine is dervied from Filter too
	public:
		virtual void Execute();
};

class TBCombine : public Filter {
	//TBCombine is derived from Filter 
	public:
		virtual void Execute();
};

class Blender : public Filter {
	//Blender is derived from Filter 
	protected:
		double factor;
	public:
		void SetFactor(double f) {
			factor = f;
		}
		virtual void Execute();
};

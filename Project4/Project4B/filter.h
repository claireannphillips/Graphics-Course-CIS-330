#include "source.h"
#include "sink.h"
#include <stdio.h>
//sink.h calls image.h 
//sink writes to files
//source.h has update function which has execute which is virtual void Execute()=0
class Filter: public Source, public sink {
	public:
		virtual void Update();
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

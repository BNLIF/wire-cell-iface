#include "WireCellIface/IConfigurable.h"
#include "WireCellUtil/Testing.h"

#include <exception>
#include <sstream>

using namespace WireCell;
using namespace std;

class Foo : public IConfigurable {
public:
    void configure(const WireCell::Configuration& cfg) {
	string out = WireCell::configuration_dumps(cfg, "json");
	cout << "Configured with:\n" << out << endl;
    }
	
    WireCell::Configuration default_configuration() const {
	string json = R"(
{
"my_int": 1,
"my_float": 6.9,
"my_string": "hello",
"my_int_array": { "0":10, "1":11, "2":12 },
"my_float_array": {"0":42.0, "1":3.14, "2":0.0},
"my_string_array": {"0":"a", "1":"b", "2":"b"},
"my_struct": { "x": 1, "y": 2, "z": 3 }
}
)";
	cout << "JSON:" << json << endl;
	Configuration cfg = configuration_loads(json, "json");
	return cfg;
    }

    
};

struct SayHi {
    void operator()(const Configuration &cfg,
		    const Configuration::path_type &childPath,
		    const Configuration &child) {

	cout << "Child:" << childPath.dump()
	     << " = " << child.data()
	     << endl;
    }
};

int main()
{
    SayHi hi;
    Configuration main_cfg;
    cout << "Empty main_cfg:"<< endl;
    configuration_visit(main_cfg, hi);

    Foo foo;
    Configuration def_cfg = foo.default_configuration();
    cout << "Default foo config:"<< endl;
    configuration_visit(def_cfg, hi);

    string fqn = "tests.instances.Foo.name";
    main_cfg.add_child(fqn, def_cfg);
    cout << "Full main_cfg:"<< endl;
    configuration_visit(main_cfg, hi);

    Configuration foo_cfg = main_cfg.get_child(fqn);
    Assert(foo_cfg == def_cfg);

    foo_cfg.put("my_int", 42);
    foo_cfg.put("my_int_array.2",99);
    cout << "Modified foo_cfg:"<< endl;
    configuration_visit(foo_cfg, hi);

    ConfigurationMerge merger(def_cfg);
    merger(foo_cfg);
    foo.configure(def_cfg);

    string bogus = R"( this is bogus json )";
    Configuration xxx;
    try {
	xxx = WireCell::configuration_loads(bogus, "json");
    }
    catch (std::exception &e) {
        cerr << "Error: " << e.what() << "\n";
    }

}

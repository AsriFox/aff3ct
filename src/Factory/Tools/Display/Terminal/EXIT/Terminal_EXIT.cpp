#include "Tools/Exception/exception.hpp"

#include "Terminal_EXIT.hpp"

using namespace aff3ct;
using namespace aff3ct::factory;

const std::string aff3ct::factory::Terminal_EXIT::name   = "Terminal EXIT";
const std::string aff3ct::factory::Terminal_EXIT::prefix = "ter";

tools::Terminal_EXIT* Terminal_EXIT
::build(const parameters &params, const int &cur_t, const int &trials, const double &I_A, const double &I_E)
{
	if (params.type == "STD") return new tools::Terminal_EXIT(params.N, params.snr, params.sig_a, cur_t, trials, I_A, I_E);

	throw tools::cannot_allocate(__FILE__, __LINE__, __func__);
}

void Terminal_EXIT::build_args(arg_map &req_args, arg_map &opt_args, const std::string p)
{
	Terminal::build_args(req_args, opt_args);

	req_args[{p+"-cw-size", "N"}] =
		{"positive_int",
		 "number of bits in the codeword."};

	req_args[{p+"-snr"}] =
		{"float",
		 "SNR value in dB."};

	req_args[{p+"-sig-a"}] =
		{"positive_float",
		 "noise variance."};

	opt_args[{p+"-type"}] =
		{"string",
		 "select the terminal type you want.",
		 "STD"};
}

void Terminal_EXIT::store_args(const tools::Arguments_reader& ar, parameters &params, const std::string p)
{
	Terminal::store_args(ar, params);

	if(ar.exist_arg({p+"-cw-size",   "N"})) params.N     = ar.get_arg_int  ({p+"-cw-size",   "N"});
	if(ar.exist_arg({p+"-snr"           })) params.snr   = ar.get_arg_float({p+"-snr"           });
	if(ar.exist_arg({p+"-sig-a"         })) params.sig_a = ar.get_arg_float({p+"-sig-a"         });
	if(ar.exist_arg({p+"-type"          })) params.type  = ar.get_arg      ({p+"-type"          });
}

void Terminal_EXIT::header(params_list& head_ter, const parameters& params)
{
	Terminal::header(head_ter, params);

	head_ter.push_back(std::make_pair("Type", params.type));
	head_ter.push_back(std::make_pair("Codeword size (N)", std::to_string(params.N)));
}

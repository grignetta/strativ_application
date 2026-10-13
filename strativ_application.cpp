/*
 * Embedded Software Engineer | Strativ - Trieste
 * An application written in C++
 *
 * No compiler needed to read this application.
 *
 * Run online (open the link and press "Run"):
 * https://www.programiz.com/online-compiler/5HhQVD1ZNLg3l
 *
 * Source code:
 * https://github.com/grignetta/strativ_application
 */
#include <iostream>
#include <string>
#include <vector>

struct Capability {
	std::string name;
	std::string evidence;
	bool demonstrated;
};

class Candidate {
public:
	std::string name() const { return "Daria"; }

	void background() const {
		std::cout
			<< "MSc, Management of Built Environment (2019)\n"
			<< "42 Vienna, software engineering curriculum (2026)\n"
			<< "Earlier work: automotive quality engineering and business analysis\n"
			<< "Projects: Unix shell, IRC server, ray tracer,\n"
			<< "          full-stack social network\n\n";
	}

	bool keepsLearning() const {
		// A career change is a feature, not an exception.
		return true;
	}
};

class Company {
public:
	virtual ~Company() = default;
	virtual std::string name() const = 0;
	virtual std::string mission() const = 0;
};

class Strativ : public Company {
public:
	std::string name() const override { return "Strativ"; }
	std::string mission() const override {
		return "Reliable embedded software for satellite missions";
	}
};

class Application {
	const Candidate& candidate_;
	const Company& company_;

	const std::vector<Capability> capabilities_ = {
		{"C/C++", "42 Vienna systems programming", true},
		{"Unix/Linux", "shell, processes, pipes and signals", true},
		{"Networking", "IRC server and socket programming", true},
		{"Debugging", "systems projects and root-cause analysis", true},
		{"Quality mindset", "automotive quality engineering", true},
		{"RTOS / real-time design", "next technical specialization", false},
		{"Flight hardware / HIL", "experience to be developed", false}
	};

public:
	Application(const Candidate& candidate, const Company& company)
		: candidate_(candidate), company_(company) {}

	void evaluate() const {
		std::cout
			<< "===========================================\n"
			<< " APPLICATION | EMBEDDED SOFTWARE ENGINEER\n"
			<< "===========================================\n\n"
			<< "Candidate: " << candidate_.name() << '\n'
			<< "Company: " << company_.name() << '\n'
			<< "Mission: " << company_.mission() << "\n\n"
			<< "// BACKGROUND\n\n";
		candidate_.background();

		std::cout << "// FLIGHT READINESS ASSESSMENT\n\n";
		for (const auto& capability : capabilities_) {
			std::cout << capability.name << " -> "
					  << (capability.demonstrated ? "FOUNDATION" : "LEARNING TARGET")
					  << "\n    " << capability.evidence << '\n';
		}

		std::cout
			<< "\n// WHY THIS MISSION?\n\n"
			<< "After working in engineering and quality, "
			<< candidate_.name()
			<< " deliberately retrained in software development. "
			<< "She discovered that the problems she enjoys most "
			<< "are close to the system: understanding how it works, "
			<< "finding why it fails, and making it reliable.\n\n"
			<< "Satellite software raises those questions to a level "
			<< "where precision and careful verification really matter. "
			<< "That responsibility is what attracts her to this role.\n\n"
			<< "// WHAT SHE BRINGS\n\n"
			<< "C/C++ practice, hands-on Unix and networking projects, "
			<< "an engineering education, and professional experience "
			<< "with quality processes and root-cause analysis.\n\n"
			<< "She has not yet worked with RTOS, onboard computers "
			<< "or flight hardware. She is ready to learn them, "
			<< "contribute where her foundation is useful, and earn "
			<< "greater responsibility through rigorous work.\n\n"
			<< "Her MSc was completed in 2019; she completed the "
			<< "42 Vienna curriculum in 2026. That path reflects "
			<< "persistence, curiosity, and a deliberate commitment "
			<< "to becoming a software engineer.\n\n";
			
		// Other opportunities
		std::cout
			<< "\n// OPEN TO OTHER OPPORTUNITIES\n\n"
			<< candidate_.name()
			<< " is particularly motivated by embedded "
			<< "and systems software development.\n"
			<< "She would also welcome the opportunity "
			<< "to contribute to other software engineering "
			<< "teams at Strativ where her C/C++ background, "
			<< "problem-solving skills, and willingness "
			<< "to learn could be valuable.\n\n";

		if (candidate_.keepsLearning()) {
			std::cout
			<< "Mission readiness: still developing.\n"
			<< "Motivation: fully operational.\n\n"
			<< "Preferred destination: Embedded Software.\n"
			<< "Alternative routes: Software Engineering.\n\n"
			<< "Next recommended step:\n"
			<< " strativ.interview(daria);\n\n";
		}
		std::cout << "Best regards,\n" << candidate_.name() << '\n';
	}
};

int main() {
	Candidate daria;
	Strativ strativ;

	// New domain. Familiar engineering instinct:
	// understand, test, improve, repeat.
	Application application(daria, strativ);
	application.evaluate();
	return 0;
}

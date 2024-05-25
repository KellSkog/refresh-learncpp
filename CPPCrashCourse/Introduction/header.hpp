extern "C" {
    void doItLikeCPP();
    void doItLikeC();
    struct MistyMountains {
        int goblin_count;
    };
}

struct Hal {
    Hal(int version) : _version{version} {
        std::cout << "I'm completely operational.\n";
    }
    ~Hal() {
        std::cout << "Stop, Dave.\n";
    }
    void sing() {
        std::cout << "Daisy Bell\n";
    }
    void sing(std::string song) {
        std::cout << song << "\n";
    }
    static void zing(std::string song) {
        std::cout << song << "\n";
    }

    const int _version;
};
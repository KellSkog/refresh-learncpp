#include <algorithm>
#include <memory> //unique_ptr
#include <ostream>
#include <string_view>
#include <variant>

namespace Philosofy {
    size_t count_dots(std::string_view str);

    template<typename T1, typename T2>
    struct MyPair {
        MyPair(T1 first, T2 second) : first_{first}, second_{second} {}
        T1 firstMember() const;
        T2 secondMember() const;
        T1 first_;
        T2 second_;
    };
    /* Note that our implementation of operator<< is a free (non-member) function. You should
     * prefer those to member functions if possible as it actually helps encapsulation*/
    template<typename T1, typename T2>
    std::ostream &operator<<(std::ostream &stream, const MyPair<T1, T2> &mp);

    /* Liskov substitution principle
     * In essence, the Liskov Substitution Principle (LSP) states that if a function works with a
     * pointer or reference to a base object, it must also work with a pointer or reference 
     * to any of its derived objects.*/
    class Shape {
        public:
        virtual ~Shape() = default;
        virtual double area() = 0; // Pure virual must be, well virtual..
        virtual void setWidth(double width) = 0; 
        virtual void setHeight(double height) = 0;
    };
    class Square : public Shape{
        public:
        double area() override { return width_ * width_; }
        virtual void setWidth(double width) override {width_ = width;}
        virtual void setHeight(double height) override {width_ = height;}

        private:
        double width_;
        // double height_;
    };
    class Rectangle : public Shape {
        public:
        double area() override { return width_ * height_;}
        virtual void setWidth(double width) override {width_ = width;}
        virtual void setHeight(double height) {height_ = height;}

        private:
        double width_;
        double height_;
    };

/* The interface segregation principle is just about what its name suggests. 
 * It is formulated as follows:
 * No client should be forced to depend on methods that it does not use.
 * Firstly, you should prefer more but smaller interfaces to a single big one. 
 * Secondly, when you're adding a derived class or are extending the functionality 
 * of an existing one, you should think before you extend the interface the class implements*/
    class IFoodProcessor {
    public:
        virtual ~IFoodProcessor() = default;
        virtual void blend() = 0;
        /* Extending IFoodProcessor would beak Blender
        void slice() override {}
        void dice() override {}*/
    };
    class Blender : public IFoodProcessor {
    public:
        void blend() override {}
        };

    class IBlender {
    public:
        virtual ~IBlender() = default;
        virtual void blend() = 0;
    };
    class ICutter {
    public:
        virtual ~ICutter() = default;
        virtual void slice() = 0;
        virtual void dice() = 0;
    };
    class AnotherFoodProcessor : public IBlender, public ICutter {
    public:
        void blend() override {}
        void slice() override {}
        void dice() override {}
    };

/* Dependency inversion is a principle useful for decoupling. 
 * In essence, it means that highlevel modules should not depend on lower-level ones. 
 * Instead, both should depend on abstractions.
 * C++ allows two ways to inverse the dependencies between your classes. The first one is the
 * regular, polymorphic approach and the second uses templates. */
    class FrontEndDeveloper {
    public:
        void developFrontEnd() {}
    };
    class BackEndDeveloper {
    public:
        void developBackEnd() {}
    };
    /*Each developer is constructed by the Project class.
     * This approach is not ideal, though, since now the higher-level concept, 
     * Project, depends on lower-level ones – modules for individual developers*/
    class Project {
    public:
        void deliver() {
            fed_.developFrontEnd();
            bed_.developBackEnd();
        }
    private:
        FrontEndDeveloper fed_;
        BackEndDeveloper bed_;
    };

/* applying dependency inversion using polymorphism
 * changes this. We can define our developers to depend on an interface as follows:*/
    class Developer {
    public:
        virtual ~Developer() = default;
        virtual void develop() = 0;
    };
    class FrontEndDev : public Developer {
    public:
        void develop() override { developFrontEnd(); }
    private:
        void developFrontEnd();
    };
    class BackEndDev : public Developer {
    public:
        void develop() override { developBackEnd(); }
    private:
        void developBackEnd();
    };

    class Proj {
    public:
    using Developers = std::vector<std::unique_ptr<Developer>>;
    explicit Proj(Developers developers) : developers_{std::move(developers)} {}
    void deliver();
    private:
    Developers developers_;
    };

    class FrontEndDev2 {
    public:
        void develop() { developFrontEnd(); }
    private:
        void developFrontEnd();
    };
    class BackEndDev2 {
    public:
        void develop() { developBackEnd(); }
    private:
        void developBackEnd();
    };

    template <typename... Devs>
    class Project2 {
    public:
    using Developers = std::vector<std::variant<Devs...>>;
    explicit Project2(Developers developers)
    : developers_{std::move(developers)} {}
    void deliver();
    private:
    Developers developers_;
    };
} // namespace Philosofy
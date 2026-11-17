#include <iostream>
#include <memory>
#include <string>

class Report {
public:
    explicit Report(const std::string& name) : name_(name) {
        std::cout << "Creating shared resource: " << name_ << '\n';
    }

    void use(const std::string& user) const {
        std::cout << user << " is using " << name_ << '\n';
    }

    ~Report() {
        std::cout << "Releasing shared resource: " << name_ << '\n';
    }

private:
    std::string name_;
};

// Both classes genuinely need to keep the same Report alive.
class Dashboard {
public:
    explicit Dashboard(std::shared_ptr<Report> report)
        : report_(std::move(report)) {}

    void display() const {
        report_->use("Dashboard");
    }

private:
    std::shared_ptr<Report> report_;
};

class Logger {
public:
    explicit Logger(std::shared_ptr<Report> report)
        : report_(std::move(report)) {}

    void record() const {
        report_->use("Logger");
    }

private:
    std::shared_ptr<Report> report_;
};

int main() {
    std::cout << "1. UNIQUE OWNERSHIP (unique_ptr)\n";
    {
        // make_unique owns one object; it is destroyed automatically
        // when this unique_ptr leaves the scope.
        std::unique_ptr<int> number = std::make_unique<int>(42);
        std::cout << "Value: " << *number << '\n';

        // unique_ptr can also manage a dynamically allocated array.
        std::unique_ptr<int[]> values = std::make_unique<int[]>(3);
        values[0] = 10;
        values[1] = 20;
        values[2] = 30;
        std::cout << "Array: ";
        for (int i = 0; i < 3; ++i) {
            std::cout << values[i] << (i == 2 ? '\n' : ' ');
        }
    }
    std::cout << "Unique resources have left scope.\n\n";

    std::cout << "2. SHARED OWNERSHIP (shared_ptr)\n";
    {
        auto report = std::make_shared<Report>("Monthly report");
        std::cout << "Owners initially: " << report.use_count() << '\n';

        Dashboard dashboard(report);
        Logger logger(report);
        std::cout << "Owners after sharing: " << report.use_count() << '\n';

        dashboard.display();
        logger.record();
        std::cout << "Both parts have finished using the resource.\n";
    }
    std::cout << "Shared owners have left scope.\n\n";

    std::cout << "3. REPEATED ALLOCATION DEMO\n";
    long long total = 0;
    for (int i = 0; i < 1000; ++i) {
        auto item = std::make_unique<int>(i);
        total += *item;
    }
    std::cout << "Completed 1000 unique_ptr allocations. Sum: "
              << total << '\n';

    std::cout << "\nProgram finished. No manual delete was needed.\n";
    return 0;
}

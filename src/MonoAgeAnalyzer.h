cpp
#ifndef MONOAGE_ANALYZER_H
#define MONOAGE_ANALYZER_H

#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <Eigen/Dense>

// Structure to hold monocyte sample data
struct MonocyteSample {
    int sample_id;
    double telomere_length;      // Telomere length measurement
    double age;                  // Patient age
    double gender;               // 0 for male, 1 for female
    double depression_score;     // Depression severity score (0-100)
    std::vector<double> features; // Additional features for ML model
    
    // Constructor
    MonocyteSample() : sample_id(0), telomere_length(0.0), age(0.0), 
                       gender(0.0), depression_score(0.0) {}
    
    MonocyteSample(int id, double tel_len, double patient_age, double gen, double dep_score) 
        : sample_id(id), telomere_length(tel_len), age(patient_age), 
          gender(gen), depression_score(dep_score) {}
};

// Main analyzer class for monocyte aging analysis
class MonoAgeAnalyzer {
private:
    std::vector<MonocyteSample> samples;
    Eigen::MatrixXd feature_matrix;
    Eigen::VectorXd target_vector;
    
public:
    // Constructor
    MonoAgeAnalyzer();
    
    // Load samples from file
    static std::vector<MonocyteSample> loadSamples(const std::string& filename);
    
    // Analyze aging patterns
    void analyzeAgingPatterns();
    
    // Predict depression risk
    double predictDepressionRisk(const MonocyteSample& sample);
    
    // Get samples
    const std::vector<MonocyteSample>& getSamples() const;
    
    // Set samples
    void setSamples(const std::vector<MonocyteSample>& new_samples);
};

#endif // MONOAGE_ANALYZER_H
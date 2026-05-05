cpp
#ifndef DEPRESSION_MODEL_H
#define DEPRESSION_MODEL_H

#include <boost/asio.hpp>
#include <Eigen/Dense>
#include <vector>

// Forward declaration assuming MonocyteSample is defined elsewhere
struct MonocyteSample;

class DepressionModel {
public:
    DepressionModel();
    ~DepressionModel();
    
    double predictRisk(const MonocyteSample& sample);
    
private:
    Eigen::MatrixXd model_weights;
    Eigen::VectorXd model_bias;
    bool is_trained;
};

#endif // DEPRESSION_MODEL_H
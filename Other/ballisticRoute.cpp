#include <iostream>
#include <vector>
#include <cmath>

// Constants
const double PI = 3.14159265358979323846;
const double EARTH_RADIUS = 6371000.0; // meters
const double G = 9.80665;              // m/s^2
const double TIME_STEP = 0.2;          // seconds

struct Point
{
    double x, y, z, t; // Coordinates and time
};

struct State
{
    double x, y, z, vx, vy, vz, t; // Position and velocity
};

// Function prototypes
double toRadians(double degrees);
std::vector<Point> simulateTrajectory(double latitude, double longitude, double launchAngle, double launchSpeed);

int main()
{
    double latitude = 36.06;     // in degrees
    double longitude = 86.40;    // in degrees
    double launchAngle = 45.0;   // in degrees
    double launchSpeed = 1000.0; // in m/s

    std::vector<Point> trajectory = simulateTrajectory(latitude, longitude, launchAngle, launchSpeed);

    for (const auto &point : trajectory)
    {
        std::cout << "Time: " << point.t << " s, Position: (" << point.x << ", " << point.y << ", " << point.z << ") meters" << std::endl;
    }

    return 0;
}

double toRadians(double degrees)
{
    return degrees * PI / 180.0;
}

std::vector<Point> simulateTrajectory(double latitude, double longitude, double launchAngle, double launchSpeed)
{
    std::vector<Point> trajectory;

    // Initial conditions
    double latRad = toRadians(latitude);
    double lonRad = toRadians(longitude);
    double launchAngleRad = toRadians(launchAngle);

    double x = EARTH_RADIUS * cos(latRad) * cos(lonRad);
    double y = EARTH_RADIUS * cos(latRad) * sin(lonRad);
    double z = EARTH_RADIUS * sin(latRad);

    double vx = launchSpeed * cos(launchAngleRad);
    double vy = launchSpeed * sin(launchAngleRad);
    double vz = 0.0;

    double t = 0.0;
    State state = {x, y, z, vx, vy, vz, t};

    // Simulation loop
    while (state.z >= 0)
    { // Continue until missile hits the ground
        // Store the current state in the trajectory
        trajectory.push_back({state.x, state.y, state.z, state.t});

        // Compute accelerations
        double r = sqrt(state.x * state.x + state.y * state.y + state.z * state.z);
        double ax = -G * state.x / (r * r * r);
        double ay = -G * state.y / (r * r * r);
        double az = -G * state.z / (r * r * r);

        // Update state using simple Euler integration
        state.vx += ax * TIME_STEP;
        state.vy += ay * TIME_STEP;
        state.vz += az * TIME_STEP;

        state.x += state.vx * TIME_STEP;
        state.y += state.vy * TIME_STEP;
        state.z += state.vz * TIME_STEP;

        state.t += TIME_STEP;
    }

    return trajectory;
}

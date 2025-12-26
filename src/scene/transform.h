#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

class Transform
{
public:
    Transform();
    ~Transform() = default;
    
    // Getters
    const glm::vec3& GetPosition() const { return position; }
    const glm::quat& GetRotation() const { return rotation; }
    const glm::vec3& GetScale() const { return scale; }
    glm::vec3 GetEulerAngles() const;
    
    // Setters
    void SetPosition(const glm::vec3& pos);
    void SetRotation(const glm::quat& rot);
    void SetRotation(const glm::vec3& eulerAngles);
    void SetScale(const glm::vec3& scl);
    
    // Transform operations
    void Translate(const glm::vec3& offset);
    void Rotate(const glm::quat& rot);
    void Rotate(float angle, const glm::vec3& axis);
    void Scale(const glm::vec3& scale);
    
    // Matrix
    glm::mat4 GetModelMatrix() const;
    
private:
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;
    
    mutable glm::mat4 modelMatrix;
    mutable bool isDirty;
    
    void UpdateMatrix() const;
};
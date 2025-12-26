#include "transform.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

Transform::Transform()
    : position(0.0f), rotation(glm::quat(1.0f, 0.0f, 0.0f, 0.0f)), scale(1.0f), isDirty(true)
{
}

glm::vec3 Transform::GetEulerAngles() const
{
    return glm::degrees(glm::eulerAngles(rotation));
}

void Transform::SetPosition(const glm::vec3& pos)
{
    position = pos;
    isDirty = true;
}

void Transform::SetRotation(const glm::quat& rot)
{
    rotation = rot;
    isDirty = true;
}

void Transform::SetRotation(const glm::vec3& eulerAngles)
{
    rotation = glm::quat(glm::radians(eulerAngles));
    isDirty = true;
}

void Transform::SetScale(const glm::vec3& scl)
{
    scale = scl;
    isDirty = true;
}

void Transform::Translate(const glm::vec3& offset)
{
    position += offset;
    isDirty = true;
}

void Transform::Rotate(const glm::quat& rot)
{
    rotation = rot * rotation;
    isDirty = true;
}

void Transform::Rotate(float angle, const glm::vec3& axis)
{
    rotation = glm::angleAxis(glm::radians(angle), glm::normalize(axis)) * rotation;
    isDirty = true;
}

void Transform::Scale(const glm::vec3& scaleFactor)
{
    scale *= scaleFactor;
    isDirty = true;
}

glm::mat4 Transform::GetModelMatrix() const
{
    if (isDirty)
    {
        UpdateMatrix();
        isDirty = false;
    }
    return modelMatrix;
}

void Transform::UpdateMatrix() const
{
    modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix *= glm::mat4_cast(rotation);
    modelMatrix = glm::scale(modelMatrix, scale);
}
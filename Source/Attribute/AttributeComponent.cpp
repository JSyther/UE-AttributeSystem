#include "AttributeComponent.h"

UAttributeComponent::UAttributeComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    InitializeAttributes();
}

void UAttributeComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UAttributeComponent::InitializeAttributes()
{
    // Example init values — these can be data-driven or designer-assigned later

    // Vital
    VitalAttributes.Add(EVitalAttribute::Health, FAttributeData(100.f, 100.f));
    VitalAttributes.Add(EVitalAttribute::Stamina, FAttributeData(50.f, 50.f));

    // Combat
    CombatAttributes.Add(ECombatAttribute::AttackPower, FAttributeData(25.f, 50.f));
    CombatAttributes.Add(ECombatAttribute::CriticalChance, FAttributeData(5.f, 10.f));

    // Elemental
    ElementalAttributes.Add(EElementalAttribute::FireAffinity, FAttributeData(10.f, 100.f));
    ElementalAttributes.Add(EElementalAttribute::IceAffinity, FAttributeData(10.f, 100.f));

    // Utility
    UtilityAttributes.Add(EUtilityAttribute::MovementSpeed, FAttributeData(600.f, 1000.f));

    // Weapon
    WeaponAttributes.Add(EWeaponAttribute::ReloadSpeed, FAttributeData(1.f, 3.f));

    // Resistance
    ResistanceAttributes.Add(EResistanceAttribute::FireResistance, FAttributeData(0.f, 100.f));
}

// ------------------ Internal Helpers ------------------

float UAttributeComponent::GetClampedAttributeValue(const FAttributeData* AttributeData) const
{
    return AttributeData ? FMath::Clamp(AttributeData->CurrentValue, 0.f, AttributeData->MaxValue) : 0.f;
}

void UAttributeComponent::ApplyDelta(FAttributeData& AttributeData, float Delta)
{
    AttributeData.CurrentValue = FMath::Clamp(AttributeData.CurrentValue + Delta, 0.f, AttributeData.MaxValue);
}

// ------------------ Attribute Getters ------------------

float UAttributeComponent::GetVitalAttribute(EVitalAttribute Attribute) const
{
    return GetClampedAttributeValue(VitalAttributes.Find(Attribute));
}

float UAttributeComponent::GetCombatAttribute(ECombatAttribute Attribute) const
{
    return GetClampedAttributeValue(CombatAttributes.Find(Attribute));
}

float UAttributeComponent::GetElementalAttribute(EElementalAttribute Attribute) const
{
    return GetClampedAttributeValue(ElementalAttributes.Find(Attribute));
}

float UAttributeComponent::GetUtilityAttribute(EUtilityAttribute Attribute) const
{
    return GetClampedAttributeValue(UtilityAttributes.Find(Attribute));
}

float UAttributeComponent::GetWeaponAttribute(EWeaponAttribute Attribute) const
{
    return GetClampedAttributeValue(WeaponAttributes.Find(Attribute));
}

float UAttributeComponent::GetResistanceAttribute(EResistanceAttribute Attribute) const
{
    return GetClampedAttributeValue(ResistanceAttributes.Find(Attribute));
}

// ------------------ Attribute Modifiers ------------------

void UAttributeComponent::ModifyVitalAttribute(EVitalAttribute Attribute, float Delta)
{
    if (FAttributeData* Found = VitalAttributes.Find(Attribute))
    {
        ApplyDelta(*Found, Delta);
    }
}

void UAttributeComponent::ModifyCombatAttribute(ECombatAttribute Attribute, float Delta)
{
    if (FAttributeData* Found = CombatAttributes.Find(Attribute))
    {
        ApplyDelta(*Found, Delta);
    }
}

void UAttributeComponent::ModifyElementalAttribute(EElementalAttribute Attribute, float Delta)
{
    if (FAttributeData* Found = ElementalAttributes.Find(Attribute))
    {
        ApplyDelta(*Found, Delta);
    }
}

void UAttributeComponent::ModifyUtilityAttribute(EUtilityAttribute Attribute, float Delta)
{
    if (FAttributeData* Found = UtilityAttributes.Find(Attribute))
    {
        ApplyDelta(*Found, Delta);
    }
}

void UAttributeComponent::ModifyWeaponAttribute(EWeaponAttribute Attribute, float Delta)
{
    if (FAttributeData* Found = WeaponAttributes.Find(Attribute))
    {
        ApplyDelta(*Found, Delta);
    }
}

void UAttributeComponent::ModifyResistanceAttribute(EResistanceAttribute Attribute, float Delta)
{
    if (FAttributeData* Found = ResistanceAttributes.Find(Attribute))
    {
        ApplyDelta(*Found, Delta);
    }
}

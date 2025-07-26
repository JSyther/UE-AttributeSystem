#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeType.h"
#include "AttributeComponent.generated.h"

/**
 * Component that manages various attribute categories such as Vital, Combat, Elemental, Utility, etc.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class YOURGAME_API UAttributeComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UAttributeComponent();

protected:
    virtual void BeginPlay() override;

public:
    // ------------------ Attribute Access ------------------

    /** Get current value of a Vital attribute */
    UFUNCTION(BlueprintCallable, Category = "Attribute|Vital")
    float GetVitalAttribute(EVitalAttribute Attribute) const;

    /** Get current value of a Combat attribute */
    UFUNCTION(BlueprintCallable, Category = "Attribute|Combat")
    float GetCombatAttribute(ECombatAttribute Attribute) const;

    /** Get current value of an Elemental attribute */
    UFUNCTION(BlueprintCallable, Category = "Attribute|Elemental")
    float GetElementalAttribute(EElementalAttribute Attribute) const;

    /** Get current value of a Utility attribute */
    UFUNCTION(BlueprintCallable, Category = "Attribute|Utility")
    float GetUtilityAttribute(EUtilityAttribute Attribute) const;

    /** Get current value of a Weapon attribute */
    UFUNCTION(BlueprintCallable, Category = "Attribute|Weapon")
    float GetWeaponAttribute(EWeaponAttribute Attribute) const;

    /** Get current value of a Resistance attribute */
    UFUNCTION(BlueprintCallable, Category = "Attribute|Resistance")
    float GetResistanceAttribute(EResistanceAttribute Attribute) const;

    // ------------------ Attribute Modifiers ------------------

    /** Modify value of a Vital attribute (additive) */
    UFUNCTION(BlueprintCallable, Category = "Attribute|Vital")
    void ModifyVitalAttribute(EVitalAttribute Attribute, float Delta);

    /** Modify value of a Combat attribute (additive) */
    UFUNCTION(BlueprintCallable, Category = "Attribute|Combat")
    void ModifyCombatAttribute(ECombatAttribute Attribute, float Delta);

    /** Modify value of an Elemental attribute (additive) */
    UFUNCTION(BlueprintCallable, Category = "Attribute|Elemental")
    void ModifyElementalAttribute(EElementalAttribute Attribute, float Delta);

    /** Modify value of a Utility attribute (additive) */
    UFUNCTION(BlueprintCallable, Category = "Attribute|Utility")
    void ModifyUtilityAttribute(EUtilityAttribute Attribute, float Delta);

    /** Modify value of a Weapon attribute (additive) */
    UFUNCTION(BlueprintCallable, Category = "Attribute|Weapon")
    void ModifyWeaponAttribute(EWeaponAttribute Attribute, float Delta);

    /** Modify value of a Resistance attribute (additive) */
    UFUNCTION(BlueprintCallable, Category = "Attribute|Resistance")
    void ModifyResistanceAttribute(EResistanceAttribute Attribute, float Delta);

    // ------------------ Attribute Storage ------------------

protected:

    /** Vital attribute map */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Vital")
    TMap<EVitalAttribute, FAttributeData> VitalAttributes;

    /** Combat attribute map */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Combat")
    TMap<ECombatAttribute, FAttributeData> CombatAttributes;

    /** Elemental attribute map */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Elemental")
    TMap<EElementalAttribute, FAttributeData> ElementalAttributes;

    /** Utility attribute map */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Utility")
    TMap<EUtilityAttribute, FAttributeData> UtilityAttributes;

    /** Weapon attribute map */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Weapon")
    TMap<EWeaponAttribute, FAttributeData> WeaponAttributes;

    /** Resistance attribute map */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|Resistance")
    TMap<EResistanceAttribute, FAttributeData> ResistanceAttributes;

private:

    // Internal helper to safely get an attribute value with clamping
    float GetClampedAttributeValue(const FAttributeData* AttributeData) const;

    // Internal helper to apply delta and clamp
    void ApplyDelta(FAttributeData& AttributeData, float Delta);
};

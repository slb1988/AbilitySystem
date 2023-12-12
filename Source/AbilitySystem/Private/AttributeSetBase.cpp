// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffectTypes.h"

UAttributeSetBase::UAttributeSetBase()
	: Health(200.0f),
	MaxHealth(200.0f),
	Mana(100.0f),
	MaxMana(150.0f),
	Strength(250.0f),
	MaxStrength(250.0f)
{
}

void UAttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health)))
	{
		Health.SetCurrentValue(FMathf::Clamp(Health.GetCurrentValue(), 0.0f, MaxHealth.GetCurrentValue()));
		Health.SetBaseValue(FMathf::Clamp(Health.GetBaseValue(), 0.0f, MaxHealth.GetBaseValue()));
		
		UE_LOG(LogTemp, Warning, TEXT("Ouch, I took some damage, now my health is : %f"), Health.GetCurrentValue());

		OnHealthChange.Broadcast(Health.GetCurrentValue(), MaxHealth.GetCurrentValue());
	}
	
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Mana)))
	{
		Mana.SetCurrentValue(FMathf::Clamp(Mana.GetCurrentValue(), 0.0f, MaxMana.GetCurrentValue()));
		Mana.SetBaseValue(FMathf::Clamp(Mana.GetBaseValue(), 0.0f, MaxMana.GetBaseValue()));
		
		UE_LOG(LogTemp, Warning, TEXT("Ouch, I took some damage, now my health is : %f"), Mana.GetCurrentValue());

		OnManaChange.Broadcast(Mana.GetCurrentValue(), MaxMana.GetCurrentValue());
	}
	
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Strength)))
	{
		Strength.SetCurrentValue(FMathf::Clamp(Strength.GetCurrentValue(), 0.0f, MaxStrength.GetCurrentValue()));
		Strength.SetBaseValue(FMathf::Clamp(Strength.GetBaseValue(), 0.0f, MaxStrength.GetBaseValue()));
		
		UE_LOG(LogTemp, Warning, TEXT("Ouch, I took some damage, now my health is : %f"), Strength.GetCurrentValue());

		OnStrengthChange.Broadcast(Strength.GetCurrentValue(), MaxStrength.GetCurrentValue());
	}
}

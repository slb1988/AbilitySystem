// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffectTypes.h"

UAttributeSetBase::UAttributeSetBase()
	: Health(200)
{
}

void UAttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health)))
	{
		UE_LOG(LogTemp, Warning, TEXT("Ouch, I took some damage, now my health is : %f"), Health.GetCurrentValue());
	}
}

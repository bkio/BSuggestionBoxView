/// MIT License, Copyright Burak Kara, burak@burak.io, https://en.wikipedia.org/wiki/MIT_License

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "SBSuggestionTextBoxCustom.h"

class BSUGGESTIONBOXVIEW_API SBExtendedInputBox : public SBSuggestionTextBoxCustom
{

public:
	FText GetInputText() const;

	void SetInputText(FText InText);

	void SetInputError(FString InError);

	void SetInputSuggestions(TArray<FString> SuggestionStrings);

	void ClearInputSuggestions();

	void MarkActiveInputSuggestion();

	FString GetSelectedInputSuggestionString();

	void NavigateDown();
	void NavigateUp();
};
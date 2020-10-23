/// MIT License, Copyright Burak Kara, burak@burak.io, https://en.wikipedia.org/wiki/MIT_License

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "SBExtendedInputBox.h"
#include "Styling/SlateColor.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateTypes.h"
#include "BSuggestionInputBox.generated.h"

class SBExtendedInputBox;
/**
 * 
 */
UCLASS()
class BSUGGESTIONBOXVIEW_API UBSuggestionInputBox : public UWidget
{
	GENERATED_BODY()
public:

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEditableTextBoxChangedEvent, const FText&, Text);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEditableTextBoxCommittedEvent, const FText&, Text, ETextCommit::Type, CommitMethod);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEditableTextBoxShowingSuggestions, const FString&, Text, const TArray<FString>&, OutSuggestions);


public:
	UBSuggestionInputBox();

	UFUNCTION(BlueprintCallable, Category = "Widget", meta = (DisplayName = "GetText (Text Box)"))
	FText GetText() const;

	UFUNCTION(BlueprintCallable, Category = "Widget", meta = (DisplayName = "SetText (Text Box)"))
	void SetText(FText InText);

	UFUNCTION(BlueprintCallable, Category = "Widget", meta = (DisplayName = "SetError (Text Box)"))
	void SetError(FString InError);

	UFUNCTION(BlueprintCallable, Category = "Widget", meta = (DisplayName = "SetSuggestions (Text Box)"))
	void SetSuggestions(TArray<FString> SuggestionStrings);

	UFUNCTION(BlueprintCallable, Category = "Widget", meta = (DisplayName = "ClearSuggestions (Text Box)"))
	void ClearSuggestions();

	UFUNCTION(BlueprintCallable, Category = "Widget", meta = (DisplayName = "MarkActiveSuggestion (Text Box)"))
	void MarkActiveSuggestion();

	UFUNCTION(BlueprintCallable, Category = "Widget", meta = (DisplayName = "GetSelectedSuggestionString (Text Box)"))
	FString GetSelectedSuggestionString();

	UFUNCTION(BlueprintCallable, Category = "Widget", meta = (DisplayName = "Navigate Up (Text Box)"))
	void NavigateUp();

	UFUNCTION(BlueprintCallable, Category = "Widget", meta = (DisplayName = "Navigate Down (Text Box)"))
	void NavigateDown();

	UFUNCTION(BlueprintCallable, Category = "Widget", meta = (DisplayName = "Has Suggestions Open (Text Box)"))
	bool HasSuggestionsOpen();


public:

	UPROPERTY(BlueprintAssignable, Category = "TextBox|Event")
	FOnEditableTextBoxChangedEvent OnTextChanged;

	UPROPERTY(BlueprintAssignable, Category = "TextBox|Event")
	FOnEditableTextBoxCommittedEvent OnTextCommitted;

	UPROPERTY(BlueprintAssignable, Category = "TextBox|Event")
	FOnEditableTextBoxShowingSuggestions OnShowingSuggestions;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance)
	FSlateColor BackgroundColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance)
	FSlateColor ForegroundColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance)
	FSlateFontInfo Font;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance)
	FText HintText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance)
	float MinDesiredWidth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance)
	float SuggestionListMaxHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance)
	FText Text;

protected:
	//~ Begin UWidget Interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	// End of UWidget

#if WITH_ACCESSIBILITY
	virtual TSharedPtr<SWidget> GetAccessibleWidget() const override;
#endif

	TSharedPtr<SBExtendedInputBox> MySuggestionTextBlock;

private:

	/** Handles changing the input text box's content. */
	void HandleInputTextChanged(const FText& InText);

	/** Handles committing the input text box's content. */
	void HandleInputTextCommitted(const FText& InText, ETextCommit::Type CommitInfo);

	/** Handles showing suggestions in the input text box. */
	void HandleInputTextShowingSuggestions(const FString& InText, TArray<FString>& OutSuggestions);
};
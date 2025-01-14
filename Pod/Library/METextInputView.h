//
//  METextInputView.h
//  MakemojiSDK
//
//  Copyright © 2015 Makemoji. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MEInputAccessoryView.h"

typedef enum
{
    MECellStyleDefault = 0,
    MECellStyleSimple, // full width simple table cell
    MECellStyleChat // Messages style table cell
} MECellStyle;

@protocol METextInputViewDelegate;

@interface METextInputView : UIView

// container view for the text input view, the send button, camera button and overlay views
@property IBOutlet UIView * textInputContainerView;

// solid background that by default uses the MEMessageEntryBackground image
@property IBOutlet UIImageView * barBackgroundImageView;

// a rounded corner overlay image view that uses the MEMessageEntryInputField image
@property IBOutlet UIImageView * textOverlayImageView;

//background view under text input
@property IBOutlet UIView * textSolidBackgroundView;

// buttons for chat actions
@property IBOutlet UIButton * sendButton;
@property IBOutlet UIButton * cameraButton;

@property IBOutlet UILabel * placeholderLabel;

// the navigation / trending keyboard bar
@property IBOutlet MEInputAccessoryView * meAccessory;

// only usable in detached input mode. adds a view on top of the Makemoji navigation bar.
@property UIView * inputAccessoryView;

@property UIReturnKeyType keyboardReturnKeyType;
@property UIKeyboardType keyboardType;
@property UIKeyboardAppearance keyboardAppearance;
@property NSAttributedString * attributedString;
@property NSString * HTMLText;

@property BOOL displayCameraButton;
@property BOOL displaySendButton;

// should trigger send message when a gif is selected from the keyboard
@property BOOL shouldAutosendGif;

@property CGFloat currentKeyboardPosition;

-(void)setDefaultFontSize:(CGFloat)fontSize;
@property CGFloat fontSize;

// textView delegate
@property (assign) id <METextInputViewDelegate> delegate;

// current state of detached input
@property BOOL detachedTextInput;

// perform detachment
-(void)detachTextInputView:(BOOL)option;

-(void)showKeyboard;
-(void)hideKeyboard;

// you can attach a custom button to this method as a action to trigger a send delegate call
-(void)sendMessage;

-(CGFloat)cellHeightForHTML:(NSString *)html atIndexPath:(NSIndexPath *)indexPath maxCellWidth:(CGFloat)width cellStyle:(MECellStyle)cellStyle;

-(void)setTextInputTextColor:(UIColor *)textColor;

@end

@protocol METextInputViewDelegate <NSObject>
    -(void)meTextInputView:(METextInputView *)inputView didTapSend:(NSDictionary *)message;
    -(void)meTextInputView:(METextInputView *)inputView didTapHypermoji:(NSString*)urlString;
    -(void)meTextInputView:(METextInputView *)inputView didTapHyperlink:(NSString*)urlString;
    -(void)meTextInputView:(METextInputView *)inputView didTapCameraButton:(UIButton*)cameraButton;
    -(void)meTextInputView:(METextInputView *)inputView didChangeFrame:(CGRect)frame;
    @optional
    -(void)meTextInputViewDidChange:(METextInputView *)inputView;
    -(void)meTextInputViewDidBeginEditing:(METextInputView *)inputView;
    -(void)meTextInputViewDidEndEditing:(METextInputView *)inputView;
@end
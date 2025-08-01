#import <objc/runtime.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <Foundation/NSNotification.h>
#import <CepheiPrefs/CepheiPrefs.h>
#import <Cephei/HBPreferences.h>
#import <Preferences/PSListController.h>
#import <Preferences/PSSpecifier.h>
#import <Preferences/PSEditableTableCell.h>
#import <Preferences/PSSwitchTableCell.h>
#import <Preferences/PSControlTableCell.h>

#import "../Components/Prefs/SwitchTableCell.h"
#import "../Components/Prefs/StepperTableCell.h"

#import "../InstagramHeaders.h"
#import "../Utils.h"
#import "../Tweak.h"

typedef NS_ENUM(NSInteger, DynamicSpecifierOperatorType) {
    EqualToOperatorType,
    NotEqualToOperatorType,
    GreaterThanOperatorType,
    LessThanOperatorType,
};

@interface SCISettingsViewController : HBListController
- (instancetype)init;
- (PSSpecifier *)newSectionWithTitle:(NSString *)header footer:(NSString *)footer;
- (PSSpecifier *)newSwitchCellWithTitle:(NSString *)titleText detailTitle:(NSString *)detailText key:(NSString *)keyText changeAction:(SEL)changeAction;
- (PSSpecifier *)newStepperCellWithTitle:(NSString *)titleText key:(NSString *)keyText min:(double)min max:(double)max step:(double)step label:(NSString *)label singularLabel:(NSString *)singularLabel;
- (PSSpecifier *)newLinkCellWithTitle:(NSString *)titleText detailTitle:(NSString *)detailText url:(NSString *)url iconURL:(NSString *)iconURL iconTransparentBG:(BOOL)iconTransparentBG;
- (void)reloadSpecifiers;
- (void)collectDynamicSpecifiersFromArray:(NSArray *)array;
- (BOOL)shouldHideSpecifier:(PSSpecifier *)specifier;
- (DynamicSpecifierOperatorType)operatorTypeForString:(NSString *)string;

- (id)readPreferenceValue:(PSSpecifier *)specifier;
- (void)setPreferenceValue:(id)value specifier:(PSSpecifier *)specifier;
@end
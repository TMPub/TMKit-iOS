//
//  UITextView+TMExtension.h
//  TMKit
//
//  Created by TMKit on 2022/8/18.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UITextView (TMExtension)

/**
 *  UITextView 只有 selectedTextRange 属性（在<UITextInput>协议里定义），这里拓展了一个方法可以将 UITextRange 类型的 selectedTextRange 转换为 NSRange 类型的 selectedRange
 */
@property(nonatomic, assign, readonly) NSRange tm_selectedRange;

/**
 *  convert UITextRange to NSRange, for example, [self tm_convertNSRangeFromUITextRange:self.markedTextRange]
 */
- (NSRange)tm_convertNSRangeFromUITextRange:(UITextRange *)textRange;

/**
 *  convert NSRange to UITextRange
 *  @return return nil if range is invalidate.
 */
- (nullable UITextRange *)tm_convertUITextRangeFromNSRange:(NSRange)range;

/**
 *  设置 text 会让 selectedTextRange 跳到最后一个字符，导致在中间修改文字后光标会跳到末尾，所以设置前要保存一下，设置后恢复过来
 */
- (void)tm_setTextKeepingSelectedRange:(NSString *)text;

/**
 *  设置 attributedText 会让 selectedTextRange 跳到最后一个字符，导致在中间修改文字后光标会跳到末尾，所以设置前要保存一下，设置后恢复过来
 */
- (void)tm_setAttributedTextKeepingSelectedRange:(NSAttributedString *)attributedText;

/**
 [UITextView scrollRangeToVisible:] 并不会考虑 textContainerInset.bottom，所以使用这个方法来代替

 @param range 要滚动到的文字区域，如果 range 非法则什么都不做
 */
- (void)tm_scrollRangeToVisible:(NSRange)range;

/**
 * 将光标滚到可视区域
 */
- (void)tm_scrollCaretVisibleAnimated:(BOOL)animated;


@end

NS_ASSUME_NONNULL_END

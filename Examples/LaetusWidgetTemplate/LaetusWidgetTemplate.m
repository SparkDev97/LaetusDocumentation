#import "LaetusWidgetTemplate.h"

@implementation LaetusWidgetTemplate
    -(void)setupWithFrame:(CGRect) frame
    {
        if(self.contentView == NULL)
        {
            self.contentView = [[UIView alloc] initWithFrame: frame];
        }

        [self.contentView setFrame: frame];
        self.contentView.backgroundColor = [UIColor redColor];
    }

    -(void) destroyContentView
    {
        if(self.contentView)
        {
            [self.contentView removeFromSuperview];
            self.contentView = NULL;
        }
    }
@end
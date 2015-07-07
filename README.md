SDFFlib provides a replacement of Marmalade SDK's CIwGxFont class for rendering bitmap fonts using signed distance field (SDF) advanced technique. Such approach allows to greatly increase visual quality of rendered text (especially for high scaling factors) while keeping acceptable performance.

If you are interested in it you can use it for free for any your projects including commercial applications.

SDFFlib's main features are:

Hiero's .fnt files support (both single and multi-pages fonts);

UTF8 (8-32 bits) and ANSI (8 bit) encodings support;

left-to-right and right-to-left drawing;

different types of horizontal and vertical alignment;

italic, bold and outline runtime styles;

text output at any angle and scale;

word wrapping;

high quality output (much better than CIwGxFont);

built-in batching subsystem to ensure high performance.

https://answers.madewithmarmalade.com/questions/21888/sdfflib-high-quality-text-rendering.html?page=3&pageSize=10&sort=votes

Please note, this fork apart from original doesn't require any *.a files, so can be used in any deployment target.
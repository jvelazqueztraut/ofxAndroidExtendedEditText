package cc.openframeworks.ofxaddons.ofxandroidextendededittext;

import android.content.Context;
import android.util.AttributeSet;
import android.view.KeyEvent;
import android.widget.EditText;
import android.widget.RelativeLayout;

public class ExtendedEditText extends EditText {
	
    public ExtendedEditText(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
 
    }
 
    public ExtendedEditText(Context context, AttributeSet attrs) {
        super(context, attrs);
 
    }
 
    public ExtendedEditText(Context context) {
        super(context);
 
    }
 
    @Override
    public boolean onKeyPreIme(int keyCode, KeyEvent event) {
        if (event.getAction() == KeyEvent.ACTION_UP && event.getKeyCode() == KeyEvent.KEYCODE_BACK) {
            dispatchKeyEvent(event);
            this.setVisibility(ExtendedEditText.INVISIBLE);
            this.setClickable(false);
            RelativeLayout r = (RelativeLayout) this.getParent();
            r.removeView(this);
            return false;
        }
        return super.onKeyPreIme(keyCode, event);
    }

}

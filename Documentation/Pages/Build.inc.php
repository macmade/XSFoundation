<div class="xsdoc-file">
    <?php
        if( !isset( $_GET[ 'xsdoc-print' ] ) )
        {
    ?>
    <div class="xsdoc-file-toc">
        <h2>Table of contents</h2>
        <h3><a href="#make">Building with Make</a></h3>
        <ul>
            <li><a href="#make-products">Products</a></li>
            <li><a href="#make-types">Build types</a></li>
            <li><a href="#make-targets">Available targets</a></li>
        </ul>
        <h3><a href="#xcode">Building with Xcode</a></h3>
        <h3><a href="#msvc">Building with VisualStudio</a></h3>
    </div>
    <?php
        }
    ?>
    <div class="xsdoc-file-content">
        <h2>Building XSFoundation</h2>
        <a name="make"></a>
        <h3>Building with Make (all platforms)</h3>
        <p>
            XSFoundation can be built using <span class="xsdoc-code"><a href="http://www.gnu.org/software/make/">GNU Make</a></span>.<br />
            Note that you are strongly encouraged to use <span class="xsdoc-code"><a href="http://clang.llvm.org">Clang</a></span> and <span class="xsdoc-code"><a href="http://llvm.org">LLVM</a></span> as compiler.
        </p>
        <p>
            From a command line prompt, while in XSFoundation's directory, just type:
        </p>
        <p class="xsdoc-code-block">
            <code>make</code>
        </p>
        <p>
            This will build the complete XSFoundation set of libraries, in the <span class="xsdoc-code">Build</span> directory.<br />
            Built architectures are:
        </p>
        <ul class="xsdoc-list-square">
            <li><span class="xsdoc-code">i386</span> (32 bits Intel)</li>
            <li><span class="xsdoc-code">x86-64</span> (64 bits Intel)</li>
            <li><span class="xsdoc-code">armv7</span> (32 bits ARM)</li>
            <li><span class="xsdoc-code">armv7s</span> (32 bits ARM)</li>
            <li><span class="xsdoc-code">arm64</span> (64 bits ARM)</li>
        </ul>
        <a name="make-products"></a>
        <h4>Products</h4>
        <ul class="xsdoc-list-square">
            <li>
                <span class="xsdoc-code">libxs.a</span><br />
                Static library archive
            </li>
            <li>
                <span class="xsdoc-code">libxs.dylib</span><br />
                Dynamic OS X library
            </li>
            <li>
                <span class="xsdoc-code">XSFoundation.framework</span><br />
                OS X framework package
            </li>
            <li>
                <span class="xsdoc-code">libxs-ios.a</span><br />
                Static library for iOS
            </li>
        </ul>
        <a name="make-types"></a>
        <h4>Build types</h4>
        <p>
            By default, XSFoundation is built in <strong>Release</strong> and <strong>Debug</strong> mode.<br />
            Note that debug symbols are stripped in <strong>Release</strong> mode, as well as XSFoundation's private symbols.
        </p>
        <a name="make-targets"></a>
        <h4>Available targets</h4>
        <h5>Release build</h5>
        <p class="xsdoc-code-block">
            <code>make release</code>
        </p>
        <p>
            This will build the XSFoundation libraries in <strong>Release</strong> mode only.
        </p>
        <h5>Debug build</h5>
        <p class="xsdoc-code-block">
            <code>make debug</code>
        </p>
        <p>
            This will build the XSFoundation libraries in <strong>Debug</strong> mode only.
        </p>
        <h5>Documentation build</h5>
        <p class="xsdoc-code-block">
            <code>make doc</code>
        </p>
        <p>
            This will generate the XSFoundation API Reference, using <span class="xsdoc-code"><a href="https://developer.apple.com/library/mac/documentation/DeveloperTools/Conceptual/HeaderDoc/intro/intro.html">HeaderDoc</a></span>, from the XSFoundation's header files.
        </p>
        <h5>Testing build</h5>
        <p class="xsdoc-code-block">
            <code>make test-debug</code><br />
            <code>make test</code>
        </p>
        <p>
            This will build and run the XSFoundation test program, in <strong>Release</strong> or <strong>Debug</strong> mode.
        </p>
        <a name="xcode"></a>
        <h3>Building with Xcode on OS X</h3>
        <p>
            XSFoundation can also be build with <span class="xsdoc-code"><a href="https://developer.apple.com/xcode/">Xcode</a></span>.<br />
            A complete Xcode project is included, containing all targets. The test program can also be built and run throught Xcode.
        </p>
        <p>
            Please note that the resulting binaries will be built in <strong>Debug</strong> mode.<br />
            For <strong>Release</strong> builds, please use <span class="xsdoc-code"><a href="http://www.gnu.org/software/make/">GNU Make</a></span>.
        </p>
        <a name="msvc"></a>
        <h3>Building with VisualStudio on Windows</h3>
        <p>
            XSFoundation can also be build with <span class="xsdoc-code"><a href="http://www.visualstudio.com">Visual Studio</a></span>.<br />
            A complete VisualStudio project is included, containing Windows specific targets. The test program can also be built and run throught VisualStudio.
        </p>
    </div>
</div>


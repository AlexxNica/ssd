<div class="black-header">
  <div class="scratch-user-menu">
    <?php if ($logged_in): ?>
      <?php print render($page['user_menu']); ?>
    <?php else: ?>
      <ul>
        <li class="menu"><a href="<?php base_path(); ?>user/login">Log In</a></li>
      </ul>
    <?php endif; ?>
  </div>
</div>  
	 
	 <div class="row">
    <div class="large-3 columns">
 <div id="logo-floater">
 <?php if ($logo || $site_title): ?>
   <?php if ($title): ?>
     <div id="branding"><strong><a href="<?php print $front_page ?>">
     <?php if ($logo): ?>
       <img src="<?php print $logo ?>" alt="<?php print $site_name_and_slogan ?>" title="<?php print $site_name_and_slogan ?>" id="logo" />
     <?php endif; ?>
     <?php print $site_html ?>
     </a></strong></div>
   <?php else: /* Use h1 when the content title is empty */ ?>
     <h1 id="branding"><a href="<?php print $front_page ?>">
     <?php if ($logo): ?>
       <img src="<?php print $logo ?>" alt="<?php print $site_name_and_slogan ?>" title="<?php print $site_name_and_slogan ?>" id="logo" />
     <?php endif; ?>
     <?php print $site_html ?>
     </a></h1>
 <?php endif; ?>
 <?php endif; ?>
 </div>
    </div>
    <div class="large-9 columns">
      <ul class="right button-group">
      <li><a href="#" class="button">Link 1</a></li>
      <li><a href="#" class="button">Link 2</a></li>
      <li><a href="#" class="button">Link 3</a></li>
      <li><a href="#" class="button">Link 4</a></li>
      </ul>
     </div>
   </div>
  
<!-- End Header and Nav -->
 
<!-- First Band (Slider) -->
 
  <div class="row">
    <div class="large-12 columns">
    <div id="slider">
	  <ul class="example-orbit" data-orbit>
	    <li>
	      <img src="http://www.placekitten.com/1000/400" alt="slide 1" />
	      <div class="orbit-caption">
	        Caption One.
	      </div>
	    </li>
	    <li class="active">
	      <img src="http://www.placekitten.com/1000/400" alt="slide 2" />
	      <div class="orbit-caption">
	        Caption Two.
	      </div>
	    </li>
	    <li>
	      <img src="http://www.placekitten.com/1000/400" alt="slide 3" />
	      <div class="orbit-caption">
	        Caption Three.
	      </div>
	    </li>
	  </ul>
    </div>
    
    <hr />
    </div>
  </div>
  
<!-- Three-up Content Blocks -->
 
  <div class="row">
    <div class="large-4 columns">
      <img src="http://placekitten.com/g/400/300" />
      <h4>This is a content section.</h4>
      <p>Bacon ipsum dolor sit amet nulla ham qui sint exercitation eiusmod commodo, chuck duis velit. Aute in reprehenderit, dolore aliqua non est magna in labore pig pork biltong. Eiusmod swine spare ribs reprehenderit culpa. Boudin aliqua adipisicing rump corned beef.</p>
    </div>
    
    <div class="large-4 columns">
      <img src="http://placekitten.com/g/400/300" />
      <h4>This is a content section.</h4>
      <p>Bacon ipsum dolor sit amet nulla ham qui sint exercitation eiusmod commodo, chuck duis velit. Aute in reprehenderit, dolore aliqua non est magna in labore pig pork biltong. Eiusmod swine spare ribs reprehenderit culpa. Boudin aliqua adipisicing rump corned beef.</p>
    </div>
    
    <div class="large-4 columns">
      <img src="http://placekitten.com/g/400/300" />
      <h4>This is a content section.</h4>
      <p>Bacon ipsum dolor sit amet nulla ham qui sint exercitation eiusmod commodo, chuck duis velit. Aute in reprehenderit, dolore aliqua non est magna in labore pig pork biltong. Eiusmod swine spare ribs reprehenderit culpa. Boudin aliqua adipisicing rump corned beef.</p>
    </div>
  
    </div>
    
<!-- Call to Action Panel -->
<div class="row">
    <div class="large-12 columns">
    
      <div class="panel">
        <h4>Get in touch!</h4>
            
        <div class="row">
          <div class="large-9 columns">
            <p>We'd love to hear from you, you attractive person you.</p>
          </div>
          <div class="large-3 columns">
            <a href="#" class="radius button right">Contact Us</a>
          </div>
        </div>
      </div>
      
    </div>
  </div>
 
  <!-- Footer -->
  
  <footer class="row">
    <div class="large-12 columns">
      <hr />
      <div class="row">
        <div class="large-6 columns">
          <p>© Copyright no one at all. Go to town.</p>
        </div>
        <div class="large-6 columns">
          <ul class="inline-list right">
            <li><a href="#">Link 1</a></li>
            <li><a href="#">Link 2</a></li>
            <li><a href="#">Link 3</a></li>
            <li><a href="#">Link 4</a></li>
          </ul>
        </div>
      </div>
    </div> 
  </footer>
    
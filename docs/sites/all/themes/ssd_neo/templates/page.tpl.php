<!-- HEADER -->
<div class="block-header">

  <!-- LOGGED IN USER MENU -->
  <div class="user-menu-header">
    <?php if ($logged_in): ?>
    <?php else: ?>
      <ul>
        <li class="menu"><a href="<?php base_path(); ?>user/login">Log In</a></li>
      </ul>
    <?php endif; ?>
  </div>

  <!-- MAIN MENU -->
  <div class="main-menu-header clearfix">
    <div class="logo-div">
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
        <span>A PROJECT OF THE</span>
        <img src="/<?php print drupal_get_path('theme', $GLOBALS['theme']); ?>/images/logo.png" alt="<?php print t('Home'); ?>" />
      </a>
    </div>
    <div class="main-menu">
      <?php print render($page['main_menu']); ?>
    </div>
  </div>
</div>

<!-- Search box placeholder hack -->
<script type="text/javascript">
  jQuery(document).ready(function () {
    jQuery("#block-search-form .form-text").attr('placeholder', '<?php print t('search') ?>')
  })
</script>

<div class="container content-container-div clearfix">
  <?php if ($messages): ?>
    <div id="messages">
      <div class="section clearfix">
        <?php print $messages; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($breadcrumb): ?>
    <div id="breadcrumb"><?php print $breadcrumb; ?></div>
  <?php endif; ?>

  <h1><?php print $title; ?></h1>

  <?php print render($page['content']); ?>

  <div class="row">
    <div class="col-md-7">
      <!-- Quick Start -->
      <?php if ($page['quick_start_region']): ?>
        <div class="quick_start_region">
          <?php print render($page['quick_start_region']); ?>
        </div>
      <?php endif; ?>
    </div>

    <div class="col-md-5">
      <!-- Orange Highlight -->
      <?php if ($page['orange_highlight_region']): ?>
        <div class="orange_highlight_region">
          <?php print render($page['orange_highlight_region']); ?>
        </div>
      <?php endif; ?>
    </div>
  </div>

  <!-- Home Blog Updates -->
  <?php if ($page['home_blog_updates']): ?>
    <div class="home_blog_updates">
      <?php print render($page['home_blog_updates']); ?>
    </div>
  <?php endif; ?>
</div>

<div class="block-footer">
  <ul class="thanks">
    <li>
      <a class="cc" href="http://creativecommons.org/licenses/by/4.0/" target="_blank">
        <img src="http://i.creativecommons.org/l/by/4.0/88x31.png" />
      </a>
    </li>
    <li class="eff">EFF thanks</li>
    <li>
      <a href="http://www.digitalrealty.com/" target="_blank">
        <img class="digital-realty" src="/<?php print drupal_get_path('theme', $GLOBALS['theme']); ?>/images/digital-realty-logo.png" />
      </a>
    </li>
    <li>&amp;</li>
    <li>
      <a href="http://nephoscale.com/" target="_blank">
        <img class="nepho-scale" src="/<?php print drupal_get_path('theme', $GLOBALS['theme']); ?>/images/nephoscale_logo.png" />
      </a>
    <li>
  </ul>

  <ul class="links">
    <li><a href="#">Thanks</a></li>
    <li><a href="#">RSS Feeds</a></li>
    <li><a href="#">Copyright Policy</a></li>
    <li><a href="#">Privacy Policy</a></li>
    <li class="last"><a href="#">Contact EFF</a></li>
  </ul>
</div>
